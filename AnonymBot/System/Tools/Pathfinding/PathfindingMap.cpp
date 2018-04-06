#include "PathfindingMap.h"

QMap< int, QMap< QPair<int, int>, int > > PathfindingMap::m_mapTranslateTable;
QMutex PathfindingMap::m_mutex;

PathfindingMap::PathfindingMap():
    m_startMapId(0),
    m_endMapId(0),
    m_cellId(INVALID),
    m_cell(INVALID),
    m_sender(NULL),
    m_running(false),
    m_finishSearch(false)
{
    initialize();
}

PathfindingMap::~PathfindingMap()
{
    stopThread();
    wait();
}

void PathfindingMap::initialize()
{
    if(m_mapTranslateTable.isEmpty())
    {
        QTime t;
        t.start();

        QList<int> sub = D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SUBAREAS);
        QList<int> ar = D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::AREAS);
        QList<int> sup = D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SUPERAREAS);

        QPair<int, int> pair;

        foreach(const int &index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::MAPPOSITIONS))
        {
            QSharedPointer<MapPositionData> position = qSharedPointerCast<MapPositionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MAPPOSITIONS, index));

            if(position->getHasPriorityOnWorldmap())
            {
                pair.first = position->getPosX();
                pair.second = position->getPosY();

                if(sub.contains(position->getSubAreaId()))
                {
                    QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, position->getSubAreaId()));
                    if(ar.contains(subArea->getAreaId()))
                    {
                        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));
                        if(sup.contains(area->getSuperAreaId()))
                        {
                            QSharedPointer<SuperAreaData> superArea = qSharedPointerCast<SuperAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUPERAREAS, area->getSuperAreaId()));
                            m_mapTranslateTable[superArea->getId()][pair] = position->getId();
                        }
                    }
                }
            }
        }

        qDebug()<<"PathfindingMap - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
    }
}

int PathfindingMap::coordsToMapId(int x, int y, int superAreaID)
{
    initialize();
    QPair<int, int> pair;

    pair.first = x;
    pair.second = y;

    return m_mapTranslateTable[superAreaID][pair];
}

QList<ChangeMapRequest> PathfindingMap::findPath(uint startMapId, uint endMapId, int cell)
{
    m_running = true;
    QTime timer;
    timer.start();

    QList<ChangeMapRequest> toBeReturned;
    m_currentMap = D2PManagerSingleton::get()->getMap(startMapId);
    m_finishSearch = false;
    m_cellsList.clear();
    m_cell = cell;
    QList<uint> path;

    loadMapInList(endMapId, startMapId, endMapId);
    loadMapInList(startMapId, startMapId, endMapId);

    Map checkArea = D2PManagerSingleton::get()->getMap(startMapId);

    QSharedPointer<SubAreaData> subAreaStart = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, checkArea.getSubAreaId()));
    QSharedPointer<AreaData> areaStart = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subAreaStart->getAreaId()));
    int areaStartId = areaStart->getSuperAreaId();

    checkArea = D2PManagerSingleton::get()->getMap(endMapId);
    QSharedPointer<SubAreaData> subAreaEnd = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, checkArea.getSubAreaId()));
    QSharedPointer<AreaData> areaEnd = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subAreaEnd->getAreaId()));
    int areaEndId = areaEnd->getSuperAreaId();

    if (areaEndId != areaStartId)
        return toBeReturned;

    m_cellsList.append(m_cell);
    MapNode currentMap = m_cellPos[startMapId];

    while (!m_finishSearch)
    {
        if(!m_running)
            return toBeReturned;

        findNeighboringMaps(currentMap, startMapId, endMapId);

        if (m_openList.isEmpty())
            return toBeReturned;

        currentMap = m_openList[0];
        currentMap.setInClosedList(true);
        currentMap.setInOpenList(false);

        m_currentMap = D2PManagerSingleton::get()->getMap(currentMap.getMapId());
        m_cell = processAdjacentCell(currentMap.getCellId());
        m_openList.removeAt(0);
        m_cellsList.append(m_cell);
    }

    m_cellsList.clear();
    MapNode recreatePath = m_cellPos[endMapId];

    while (recreatePath.getMapId() != startMapId)
    {
        path.prepend(recreatePath.getMapId());
        m_cellsList.prepend(recreatePath.getCellId());
        recreatePath = m_cellPos[recreatePath.getParent()];
    }

    for (int i = 0; i < path.size(); i++)
    {
        ChangeMapRequest tmp;
        tmp.cellId = m_cellsList[i];
        tmp.mapId = path[i];
        toBeReturned.append(tmp);
    }

    qDebug()<<"PathfindingMap - Temps de calcul:"<<timer.elapsed();
    return toBeReturned;
}

void PathfindingMap::stopThread()
{
    m_running = false;
}

void PathfindingMap::requestPath(uint startMapId, uint endMapId, int cellId, SocketIO *sender)
{
    m_startMapId = startMapId;
    m_endMapId = endMapId;
    m_cellId = cellId;
    m_sender = sender;

    start();
}

void PathfindingMap::run()
{
    m_running = true;

    m_mutex.lock();

    QList<ChangeMapRequest> path;

    if (m_running)
        path = findPath(m_startMapId, m_endMapId, m_cellId);

    if(m_running)
        emit foundPath(path, m_sender);

    m_mutex.unlock();
}

void PathfindingMap::findNeighboringMaps(MapNode c_MapNode, uint startMapId, uint endMapId)
{
    QList<uint> sides;

    bool isTop = false;
    bool isBottom = false;
    bool isRight = false;
    bool isLeft = false;

    Map currentMap = D2PManagerSingleton::get()->getMap(c_MapNode.getMapId());

    uint top = currentMap.getTopMapId();
    uint bottom = currentMap.getBottomMapId();
    uint right = currentMap.getRightMapId();
    uint left = currentMap.getLeftMapId();
    sides<<top<<bottom<<right<<left;

    for (int i = 0; i < sides.size(); i++)
    {
        Map mainMap = D2PManagerSingleton::get()->getMap(sides[i]);

        if(mainMap.isInit())
        {
            QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, mainMap.getSubAreaId()));
            QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

            uint mapId = coordsToMapId(mainMap.getPosition().getX(), mainMap.getPosition().getY(), area->getSuperAreaId());
            sides[i] = mapId;

            switch (i)
            {
            default:
                qDebug()<<"ERREUR - Pathfinging map";
                break;

            case 0:
                isTop = D2PManagerSingleton::get()->getMap(mapId).isInit();
                break;

            case 1:
                isBottom = D2PManagerSingleton::get()->getMap(mapId).isInit();
                break;

            case 2:
                isRight = D2PManagerSingleton::get()->getMap(mapId).isInit();
                break;

            case 3:
                isLeft = D2PManagerSingleton::get()->getMap(mapId).isInit();
            }
        }
    }

    loadMapInList(sides[0], startMapId, endMapId);
    loadMapInList(sides[1], startMapId, endMapId);
    loadMapInList(sides[2], startMapId, endMapId);
    loadMapInList(sides[3], startMapId, endMapId);

    PathInfos infos;

    int cellId = checkMap(c_MapNode.getMapId(), sides[0], MapSide::TOP);
    if (cellId != INVALID && isTop)
    {
        infos = Pathfinding::findPath(m_cell, cellId, c_MapNode.getMapId(), true);

        if (!infos.path.isEmpty())
            addMap(sides[0], cellId, c_MapNode, endMapId);
    }

    cellId = checkMap(c_MapNode.getMapId(), sides[1], MapSide::BOTTOM);
    if (cellId != INVALID && isBottom)
    {
        infos = Pathfinding::findPath(m_cell, cellId, c_MapNode.getMapId(), true);

        if (!infos.path.isEmpty())
            addMap(sides[1], cellId, c_MapNode, endMapId);
    }

    cellId = checkMap(c_MapNode.getMapId(), sides[2], MapSide::RIGHT);
    if (cellId != INVALID && isRight)
    {
        infos = Pathfinding::findPath(m_cell, cellId, c_MapNode.getMapId(), true);

        if (!infos.path.isEmpty())
            addMap(sides[2], cellId, c_MapNode, endMapId);
    }

    cellId = checkMap(c_MapNode.getMapId(), sides[3], MapSide::LEFT);
    if (cellId != INVALID && isLeft)
    {
        infos = Pathfinding::findPath(m_cell, cellId, c_MapNode.getMapId(), true);

        if (!infos.path.isEmpty())
            addMap(sides[3], cellId, c_MapNode, endMapId);
    }

    sortOpenList();
}

void PathfindingMap::loadMapInList(uint mapId, uint startMapId, uint endMapId)
{
    if (!m_cellPos.contains(mapId))
    {
        uint i = mapId;
        m_cellPos[mapId] = MapNode(i, D2PManagerSingleton::get()->getMap(i).getPosition().getX(), D2PManagerSingleton::get()->getMap(i).getPosition().getY());

        bool appli = false;
        if (mapId == startMapId)
        {
            appli = true;
            m_cellPos[mapId].setClosed(false);
            m_cellPos[mapId].setInClosedList(false);
            m_cellPos[mapId].setStarted(true);
            m_cellPos[mapId].setMapId(i);
            m_cellPos[mapId].setG(0);
        }

        if (mapId == endMapId)
        {
            appli = true;
            m_cellPos[mapId].setClosed(true);
            m_cellPos[mapId].setInClosedList(true);
            m_cellPos[mapId].setStarted(false);
            m_cellPos[mapId].setMapId(i);
        }
        if (appli == false)
        {
            m_cellPos[mapId].setClosed(false);
            m_cellPos[mapId].setStarted(false);
            m_cellPos[mapId].setInClosedList(false);
            m_cellPos[mapId].setInOpenList(false);
            m_cellPos[mapId].setMapId(i);
        }
        m_cellPos[mapId].calculH(m_cellPos[endMapId]);
    }

}

void PathfindingMap::addMap(int map, int cell, MapNode c_MapNode, uint endMapId)
{
    if(m_cellPos[map].getMapId() == endMapId)
    {
        m_cellPos[map].setParent(c_MapNode.getMapId());
        m_cellPos[map].setCellId(cell);
        m_finishSearch = true;

        if (!m_openList.contains(m_cellPos[map]))
            m_openList.append(m_cellPos[map]);

        return;
    }

    if (m_cellPos[map].getInOpenList() == false && m_cellPos[map].getInClosedList() == false)
    {
        m_cellPos[map].setParent(c_MapNode.getMapId());
        m_cellPos[map].setInOpenList(true);
        m_cellPos[map].setG(c_MapNode.getG() + 10);
        m_cellPos[map].setF(m_cellPos[map].getG() + m_cellPos[map].getH());
        m_cellPos[map].setCellId(cell);
        m_openList.append(m_cellPos[map]);
    }
}

int PathfindingMap::getCellIdFromPoint(int x, int y)
{
    foreach (MapNode node, m_cellPos)
    {
        if (node.getX() == x && node.getY() == y)
            return node.getMapId();
    }
}

int PathfindingMap::processAdjacentCell(uint cellId)
{

    QList<uint> edgeCells;
    QList<uint> adjacentCells;

    edgeCells<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559
            <<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532
           <<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559;
    adjacentCells<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13
                <<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559
               <<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532;

    return adjacentCells[edgeCells.indexOf(cellId)];


}

void PathfindingMap::sortOpenList()
{
    bool ok = false;
    while(ok == false)
    {
        ok = true;
        MapNode nodeToSort;
        for (int i = 0; i < m_openList.size() - 1 ; i++)
        {
            if (m_openList[i].getF() > m_openList[i + 1].getF())
            {
                nodeToSort = m_openList[i];
                m_openList[i] = m_openList[i+1];
                m_openList[i+1] = nodeToSort;
                ok = false;
            }
        }
    }
}

int PathfindingMap::checkMap(uint map, uint sideMapId, MapSide mapSide)
{
    QList<uint> edgeCells;
    QList<uint> adjacentCells;
    Map adjacentMap;
    Map my_map = D2PManagerSingleton::get()->getMap(map);

    edgeCells.clear();
    adjacentCells.clear();

    if(mapSide == MapSide::TOP)
    {
        edgeCells<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13;
        adjacentCells<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559;
        adjacentMap = D2PManagerSingleton::get()->getMap(sideMapId);;
    }

    else if(mapSide == MapSide::BOTTOM)
    {
        edgeCells<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559;
        adjacentCells<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13;
        adjacentMap = D2PManagerSingleton::get()->getMap(sideMapId);;
    }

    else if(mapSide == MapSide::LEFT)
    {
        edgeCells<<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532;
        adjacentCells<<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559;
        adjacentMap = D2PManagerSingleton::get()->getMap(sideMapId);;
    }

    else if(mapSide == MapSide::RIGHT)
    {
        edgeCells<<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559;
        adjacentCells<<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532;
        adjacentMap = D2PManagerSingleton::get()->getMap(sideMapId);;
    }

    for(int i = 0; i < edgeCells.size(); i++)
    {
        if(!my_map.getCellData()[edgeCells[i]].isWalkable())
        {
            edgeCells.removeAt(i);
            adjacentCells.removeAt(i);
            i--;
        }
    }

    int originalSize =  edgeCells.size();
    int deleteCount = 0;

    for(int i = 0; i < originalSize; i++)
    {
        if(!adjacentMap.getCellData()[adjacentCells[i]].isWalkable())
        {
            edgeCells.removeAt(i - deleteCount);
            deleteCount++;
        }
    }

    while (!edgeCells.isEmpty())
    {
        int randomIndex = (rand() % (edgeCells.size()));

        if (!Pathfinding::findPath(m_cell, edgeCells[randomIndex], map).path.isEmpty())
            return edgeCells[randomIndex];

        edgeCells.removeAt(randomIndex);
    }

    return INVALID;
}
