#include "Pathfinding.h"
QMap< uint, QPair<uint, uint> > Pathfinding::coordinates;

Pathfinding::Pathfinding()
{
}

QPair<uint, uint> Pathfinding::getCoordinates(uint cellId)
{
    if (Pathfinding::coordinates.isEmpty())
    {
        int mapWidth = 14;
        int mapHeight = 20;

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        uint processedMapId = 0;

        while(d < mapHeight)
        {
            c = 0;
            while(c < mapWidth)
            {
                Pathfinding::coordinates[processedMapId] = QPair<uint, uint>(a+c,  b+c);
                processedMapId++;
                c++;
            }
            a++;
            c = 0;
            while(c < mapWidth)
            {
                Pathfinding::coordinates[processedMapId] = QPair<uint, uint>(a+c,  b+c);
                processedMapId++;
                c++;
            }
            b--;
            d++;
        }
    }

    return Pathfinding::coordinates[cellId];
}

PathInfos Pathfinding::findPath(uint startId, uint endId, uint mapId, bool mount, bool diag, QList<uint> entities)
{
    PathInfos ifNotFound;
    m_currentMap.clear();
    m_cellPos.clear();
    m_finishSearch = false;
    m_openList.clear();

    m_currentMap = D2PManagerSingleton::get()->getMap(mapId).getCellData();
    foreach (CellData cell, m_currentMap)
        m_cellHeight[cell.getId()] = cell.getFloor();

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    uint processedMapId = 0;

    while(d < 20)
    {
        c = 0;
        while(c < 14)
        {
            m_cellPos[processedMapId] = Node(processedMapId, a + c, b + c);
            processedMapId++;
            c++;
        }
        a++;
        c = 0;
        while(c < 14)
        {
            m_cellPos[processedMapId] = Node(processedMapId, a + c, b + c);
            processedMapId++;
            c++;
        }
        b--;
        d++;
    }

    foreach (CellData currentCell, m_currentMap)
    {
        bool appli = false;
        if (currentCell.getId() == startId)
        {
            appli = true;
            m_cellPos[currentCell.getId()].setClosed(false);
            m_cellPos[currentCell.getId()].setInClosedList(false);
            m_cellPos[currentCell.getId()].setStarted(true);
            m_cellPos[currentCell.getId()].setWalkable(currentCell.isWalkable());
        }

        if (currentCell.getId() == endId)
        {
            appli = true;
            m_cellPos[currentCell.getId()].setClosed(true);
            m_cellPos[currentCell.getId()].setInClosedList(true);
            m_cellPos[currentCell.getId()].setStarted(false);
            m_cellPos[currentCell.getId()].setWalkable(currentCell.isWalkable());
        }

        if (appli == false)
        {
            m_cellPos[currentCell.getId()].setClosed(false);
            m_cellPos[currentCell.getId()].setStarted(false);
            m_cellPos[currentCell.getId()].setInClosedList(false);
            m_cellPos[currentCell.getId()].setInOpenList(false);
        }

        if (entities.contains(currentCell.getId()))
            m_cellPos[currentCell.getId()].setWalkable(false);
        else
            m_cellPos[currentCell.getId()].setWalkable(currentCell.isWalkable());

        m_cellPos[currentCell.getId()].calculH(m_cellPos[endId]);
    }

    Node currentNode(m_cellPos[startId]);
    int k = 0;
    while (!m_finishSearch)
    {
        findNeighboringCell(currentNode, diag, entities);

        if (m_openList.isEmpty())
            return ifNotFound;

        currentNode = m_openList[0];
        currentNode.setInClosedList(true);
        currentNode.setInOpenList(false);
        m_openList.removeAt(0);
        k++;
    }

    Node recreatePath = m_cellPos[endId];
    QList<Node> path;
    while(recreatePath.getCellId() != m_cellPos[startId].getCellId())
    {
        path.prepend(recreatePath);
        recreatePath = m_cellPos[recreatePath.getParent()];
    }
    path.prepend(Node(m_cellPos[startId]));

    PathInfos infos;
    QList<uint> finalPath;
    foreach (Node node, path)
        finalPath.append(node.getCellId());

    infos.time = processTime(path, mount);
    finalPath = compressPath(retraceOrientation(path));
    infos.path.clear();
    infos.path = finalPath;

    return infos;
}

NearestPathInfos Pathfinding::findNearestPath(uint startCell, uint interactiveElementCell, uint mapId, bool mount, bool diag, QList<uint> entities)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    uint processedMapId = 0;

    while(d < 20)
    {
        c = 0;
        while(c < 14)
        {
            m_cellPos[processedMapId] = Node(processedMapId, a + c, b + c);
            processedMapId++;
            c++;
        }
        a++;
        c = 0;
        while(c < 14)
        {
            m_cellPos[processedMapId] = Node(processedMapId, a + c, b + c);
            processedMapId++;
            c++;
        }
        b--;
        d++;
    }

    NearestPathInfos toReturn;
    int m_x = m_cellPos[interactiveElementCell].getX();
    int m_y = m_cellPos[interactiveElementCell].getY();
    QMap<double, int> cellsMap;
    foreach (CellData cell, D2PManagerSingleton::get()->getMap(mapId).getCellData())
    {
        int x = m_cellPos[cell.getId()].getX();
        int y = m_cellPos[cell.getId()].getY();

        if (cell.isWalkable() && (cell.getId() != interactiveElementCell))
            cellsMap[sqrt(pow((m_x - x), 2) + pow((m_y - y), 2))] = cell.getId();
    }

    QList<double> dist = cellsMap.keys();
    qSort(dist.begin(), dist.end());

    int i = 0;
    PathInfos result;
    while (result.path.isEmpty() && i < 560)
    {
        result = findPath(startCell, cellsMap[dist[i]], mapId, mount, diag, entities);
        i++;
    }

    toReturn.dist = dist[i--];
    toReturn.time = result.time;
    toReturn.path = result.path;

    return toReturn;
}


void Pathfinding::initializeCurrentMap(int mapId)
{
    m_currentMap = D2PManagerSingleton::get()->getMap(mapId).getCellData();
}


void Pathfinding::findNeighboringCell(Node c_node, bool diag = true, QList<uint> entities)
{
    QList<int> top;
    top<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13;
    QList<int> top_2;
    top_2<<14<<15<<16<<17<<18<<19<<20<<21<<22<<23<<24<<25<<26<<27;
    QList<int> bottom;
    bottom<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559;
    QList<int> bottom_2;
    bottom_2<<519<<520<<521<<522<<523<<524<<525<<526<<527<<528<<529<<530<<531;
    QList<int> right;
    right<<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559;
    QList<int> right_2;
    right_2<<13<<41<<69<<97<<125<<153<<181<<209<<237<<265<<293<<321<<349<<377<<405<<433<<461<<489<<517<<545;
    QList<int> left;
    left<<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532;
    QList<int> left_2;
    left_2<<14<<42<<70<<98<<126<<154<<182<<210<<238<<266<<294<<322<<350<<378<<406<<434<<462<<490<<518<<546;

    Node cell_1 = Node(getCellIdFromPoint(c_node.getX() - 1, c_node.getY() - 1), c_node.getX() - 1, c_node.getY() - 1); // 1
    Node cell_2 = Node(getCellIdFromPoint(c_node.getX() - 1,  c_node.getY()), c_node.getX() - 1,  c_node.getY()); // 2
    Node cell_3 = Node(getCellIdFromPoint(c_node.getX() - 1, c_node.getY() + 1), c_node.getX() - 1, c_node.getY() + 1); // 3
    Node cell_4 = Node(getCellIdFromPoint(c_node.getX(), c_node.getY() - 1), c_node.getX(), c_node.getY() - 1); // 4
    Node cell_5 = Node(getCellIdFromPoint(c_node.getX(),  c_node.getY() + 1), c_node.getX(),  c_node.getY() + 1); // 5
    Node cell_6 = Node(getCellIdFromPoint(c_node.getX() + 1, c_node.getY() - 1), c_node.getX() + 1, c_node.getY() - 1); // 6
    Node cell_7 = Node(getCellIdFromPoint(c_node.getX() + 1, c_node.getY()), c_node.getX() + 1, c_node.getY()); // 7
    Node cell_8 = Node(getCellIdFromPoint(c_node.getX() + 1, c_node.getY() + 1), c_node.getX() + 1, c_node.getY() + 1); // 8

    QList<Node> cellsToAdd;
    cellsToAdd<<Node(getCellIdFromPoint(c_node.getX() - 1, c_node.getY() - 1), c_node.getX() - 1, c_node.getY() - 1)
             <<Node(getCellIdFromPoint(c_node.getX() - 1,  c_node.getY()), c_node.getX() - 1,  c_node.getY())
            <<Node(getCellIdFromPoint(c_node.getX() - 1, c_node.getY() + 1), c_node.getX() - 1, c_node.getY() + 1)
           <<Node(getCellIdFromPoint(c_node.getX(), c_node.getY() - 1), c_node.getX(), c_node.getY() - 1)
          <<Node(getCellIdFromPoint(c_node.getX(),  c_node.getY() + 1), c_node.getX(),  c_node.getY() + 1)
         <<Node(getCellIdFromPoint(c_node.getX() + 1, c_node.getY() - 1), c_node.getX() + 1, c_node.getY() - 1)
        <<Node(getCellIdFromPoint(c_node.getX() + 1, c_node.getY()), c_node.getX() + 1, c_node.getY())
       <<Node(getCellIdFromPoint(c_node.getX() + 1, c_node.getY() + 1), c_node.getX() + 1, c_node.getY() + 1);

    for (int i = 0; i < cellsToAdd.size(); i++)
        cellsToAdd[i].setOrientation(i);

    if (!diag)
    {
        removeNeightboring(cellsToAdd, cell_1);
        removeNeightboring(cellsToAdd, cell_3);
        removeNeightboring(cellsToAdd, cell_6);
        removeNeightboring(cellsToAdd, cell_8);
    }

    if (top.contains(c_node.getCellId()))
    {
        removeNeightboring(cellsToAdd, cell_2);
        removeNeightboring(cellsToAdd, cell_3);
        removeNeightboring(cellsToAdd, cell_5);
    }
    if (top_2.contains(c_node.getCellId()))
        removeNeightboring(cellsToAdd, cell_3);
    if (bottom.contains(c_node.getCellId()))
    {
        removeNeightboring(cellsToAdd, cell_4);
        removeNeightboring(cellsToAdd, cell_6);
        removeNeightboring(cellsToAdd, cell_7);
    }
    if (bottom_2.contains(c_node.getCellId()))
        removeNeightboring(cellsToAdd, cell_6);
    if (right.contains(c_node.getCellId()))
    {
        removeNeightboring(cellsToAdd, cell_5);
        removeNeightboring(cellsToAdd, cell_7);
        removeNeightboring(cellsToAdd, cell_8);
    }
    if (right_2.contains(c_node.getCellId()))
        removeNeightboring(cellsToAdd, cell_8);
    if (left.contains(c_node.getCellId()))
    {
        removeNeightboring(cellsToAdd, cell_1);
        removeNeightboring(cellsToAdd, cell_2);
        removeNeightboring(cellsToAdd, cell_4);
    }
    if (left_2.contains(c_node.getCellId()))
        removeNeightboring(cellsToAdd, cell_1);


    foreach (Node cell, cellsToAdd)
    {
        int _floor = m_cellHeight[cell.getCellId()];
        int currentFloor = m_cellHeight[c_node.getCellId()];

        if (!((_floor - 30 == currentFloor) || (_floor + 30 == currentFloor) || (_floor == currentFloor)))
            removeNeightboring(cellsToAdd, cell);
        else if (entities.contains(cell.getCellId()))
            removeNeightboring(cellsToAdd, cell);
    }

    foreach (Node cell, cellsToAdd)
        addCell(cell, c_node);

    sortOpenList();
}

void Pathfinding::addCell(Node cell, Node c_node)
{
    int _cell = cell.getCellId();

    if (m_cellPos[_cell].getWalkable() == true)
    {
        m_cellPos[_cell].setOrientation(cell.getOrientation());

        if(m_cellPos[_cell].getClosed() == true)
        {
            m_cellPos[_cell].setParent(c_node.getCellId());
            m_finishSearch = true;
            return;
        }

        if (m_cellPos[_cell].getInOpenList() == false && m_cellPos[_cell].getInClosedList() == false)
        {
            m_cellPos[_cell].setParent(c_node.getCellId());
            m_cellPos[_cell].setInOpenList(true);
            m_cellPos[_cell].setG(c_node.getG() + 10);
            m_cellPos[_cell].setF(m_cellPos[_cell].getG() + m_cellPos[_cell].getH());
            m_openList.append(m_cellPos[_cell]);
        }
    }
}

int Pathfinding::getCellIdFromPoint(int x, int y)
{
    return (x - y) * 14 + y + (x - y) / 2;
}

void Pathfinding::sortOpenList()
{
    bool ok = false;
    while(ok == false)
    {
        ok = true;
        Node nodeToSort;

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

void Pathfinding::removeNeightboring(QList<Node> &addCells, Node cell)
{
    int i = 0;
    foreach (Node _cell, addCells)
    {
        if (_cell.getCellId() == cell.getCellId())
        {
            addCells.removeAt(i);
            return;
        }
        i++;
    }
}

int Pathfinding::processTime(QList<Node> path, bool mount)
{
    int timer = 0;
    if (path.size() <= 2)
    {
        if (mount)
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i].getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=MOUNT_WALKING_DIAGONAL_HORIZONTAL;
                else if (orientation == 2 || orientation == 5)
                    timer+=MOUNT_WALKING_DIAGONAL_VERTICAL;
                else
                    timer+=MOUNT_WALKING;
            }
        }
        else
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i].getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=WALKING_DIAGONAL_HORIZONTAL;
                else if (orientation == 2 || orientation == 5)
                    timer+=WALKING_DIAGONAL_VERTICAL;
                else
                    timer+=WALKING;
            }
        }
    }
    else
    {
        if (mount)
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i].getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=MOUNT_RUNNING_DIAGONAL_HORIZONTAL;
                else if (orientation == 2 || orientation == 5)
                    timer+=MOUNT_RUNNING_DIAGONAL_VERTICAL;
                else
                    timer+=MOUNT_RUNNING;
            }
        }
        else
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i].getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=RUNNING_DIAGONAL_HORIZONTAL;
                else if (orientation == 2 || orientation == 5)
                    timer+=RUNNING_DIAGONAL_VERTICAL;
                else
                    timer+=RUNNING;
            }
        }
    }

    return timer;
}

QList<uint> Pathfinding::compressPath(QList<Node> path)
{
//    uint i = path.size() - 1;
//    while(i > 0)
//    {
//        if(path[i].getOrientation() == path[i - 1].getOrientation())
//        {
//            path.removeAt(i);
//            i--;
//        }
//        else
//            i--;
//    }

    QList<uint> finalPath;
    foreach (Node node, path)
        finalPath << node.getCellId();

    return finalPath;
}

QList<Node> Pathfinding::retraceOrientation(QList<Node> path)
{
    for (int i = 0; i < path.size() - 1; i++)
    {
        QPoint pointA(Pathfinding::getCoordinates(i).first, Pathfinding::getCoordinates(i).second);
        QPoint pointB(Pathfinding::getCoordinates(i+1).first, Pathfinding::getCoordinates(i+1).second);

        int a = pointB.x() - pointA.x();
        int b = pointA.y() - pointB.y();
        int c = acos(a / sqrt(pow(a, 2) + pow(b, 2))) * 180 / M_PI * (pointA.y() > pointA.y() ? -1 : 1);
        c = round(c / 45) + 1;

        if (c < 0)
            c += 8;

        path[i].setOrientation(c);
    }

    path.last().setOrientation(-1);
    return path;
}
