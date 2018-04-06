#include "TestPathfinding.h"

int TestPathfinding::minX = 0;
int TestPathfinding::maxX = 34;
int TestPathfinding::minY = -19;
int TestPathfinding::maxY = 14;

bool operator<(const QPoint& lhs, const QPoint& rhs)
{
    if (lhs.x() < rhs.x())
        return true;
    else if (lhs.x() == rhs.x())
        return lhs.y() < rhs.y();
    else
        return false;
}

TestPathfinding::TestPathfinding()
{
}

MovementPath TestPathfinding::findPath(uint mapId, uint _start, uint _end, bool diag, bool entity, bool isFighting, QList<uint> entities,  bool blockLast, bool mount)
{   
    return TestPathfinding().processFindPath(D2PManagerSingleton::get()->getMap(mapId).getCellData(), MapPoint::fromCellId(_start), MapPoint::fromCellId(_end), diag, entity, isFighting, entities, blockLast, mount);
}

MovementPath TestPathfinding:: processFindPath(QList<CellData> map, MapPoint start, MapPoint end, bool diag, bool entity, bool isFighting, QList<uint> entities, bool blockLast, bool mount)
{
    m_movPath.setStart(start);
    m_movPath.setEnd(end);
    m_AllowTroughEntity = entity;
    m_AllowDiagCornering = diag;
    m_IsFighting = isFighting;
    m_entites = entities;
    m_mount = mount;

    if (blockLast)
        map[end.getCellId()].setAllowWalk(2);

    findPathInternal(map, start, end, diag);
    return m_movPath;
}

bool TestPathfinding::isOpened(int y, int x) const
{
    return m_mapStatus[QPoint(x,y)].getOpened();
}

bool TestPathfinding::isClosed(int y, int x) const
{
    if (!m_mapStatus.keys().contains(QPoint(x,y)))
        return false;

    return m_mapStatus[QPoint(x,y)].getClosed();
}

uint TestPathfinding::nearerSquare()
{
    int i = -1;
    int thisF = 0;
    int min = 9999999;
    uint indexFound = 0;
    uint len = m_openList.size();

    while (i++ < len)
    {
        thisF = m_mapStatus[m_openList[i]].getHeuristic() + m_mapStatus[m_openList[i]].getMovementCost();

        if (thisF <= min)
        {
            min = thisF;
            indexFound = i;
        }
    }

    return indexFound;
}

void TestPathfinding::closeSquare(int x, int y)
{
    int i = 0;
    foreach (QPoint p, m_openList)
    {
        if (p.y() == y && p.x() == x)
        {
            m_openList.removeOne(p);
            break;
        }
    }

    m_mapStatus[QPoint(x,y)].setOpened(false);
    m_mapStatus[QPoint(x,y)].setClosed(true);
}

void TestPathfinding::openSquare(int y, int x, QPoint parent, uint movCost, uint heuristic, bool replace)
{
    if (!replace)
    {
        int i = 0;
        int len = m_openList.size();
        while (i < len)
        {
            if (m_openList[i].y() == y && m_openList[i].x() == x)
            {
                replace = true;
                break;
            }
            i++;
        }
    }

    if (!replace)
    {
        m_openList << QPoint(x,y);
        m_mapStatus[QPoint(x,y)] = CellInfo(heuristic, QPoint(), true, false);
    }

    m_mapStatus[QPoint(x,y)].setParent(parent);
    m_mapStatus[QPoint(x,y)].setMovementCost(movCost);
}

void TestPathfinding::movementPathFromArray(QList<MapPoint> returnPath)
{
    uint s = returnPath.size();
    for (int i = 0; i < s - 1; i++)
    {
        PathElement pE;
        MapPoint tmp = pE.getStep();
        tmp.setX(returnPath[i].getX());
        tmp.setY(returnPath[i].getY());
        tmp.setCellId(returnPath[i].getCellId());

        pE.setStep(tmp);
        pE.setOrientation(returnPath[i].orientationTo(returnPath[i + 1]));
        m_movPath.addPoint(pE);
    }

    m_movPath.processTime(m_mount);
}

void TestPathfinding::initPathFrame()
{
    m_DCost = 15;
    m_HVCost = 10;
    m_HeuristicCost = 10;

    pathFrame();
}

void TestPathfinding::pathFrame()
{
    int n = 0;
    int j = 0;
    int i = 0;
    MapPoint mp;
    float heuristic = 0;
    float pointWeight = 0;
    float movementCost = 0;
    float distanceTmpToEnd = 0;
    bool cellOnEndLine = false;
    bool cellOnStartLine = false;
    bool cellOnEndColumn = false;
    bool cellOnStartColumn = false;

    if (m_openList.size() > 0 && !isClosed(m_endY, m_endX))
    {
        while (m_openList.size() > 0 && !isClosed(m_endY, m_endX))
        {
            n = nearerSquare();
            m_nowY = m_openList[n].y();
            m_nowX = m_openList[n].x();
            m_previousCellId = MapPoint::fromCoords(m_nowX, m_nowY).getCellId();
            closeSquare(m_nowX, m_nowY);

            j = m_nowY - 1;
            while (j < m_nowY + 2)
            {
                i = m_nowX - 1;
                while(i < m_nowX + 2)
                {
                    if ((j >= TestPathfinding::minY) && (j < TestPathfinding::maxY) && (i >= TestPathfinding::minX) && (i < TestPathfinding::maxX) &&
                            (!((j == m_nowY) && (i == m_nowX))) && ((m_allowDiag) || (j == m_nowY) || (i == m_nowX) &&
                                                                    ((m_AllowDiagCornering) || (j == m_nowY) || (i == m_nowX) ||
                                                                     (CellInfo::pointMov(m_map, m_nowX,j,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)) ||
                                                                     (CellInfo::pointMov(m_map, i,m_nowY,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)))))
                    {
                        if (!((!CellInfo::pointMov(m_map, m_nowX,j,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)) && (!CellInfo::pointMov(m_map, i,m_nowY,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)) &&
                              (!m_IsFighting) && (m_allowDiag)))
                        {
                            if (CellInfo::pointMov(m_map, i,j,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites))
                            {
                                if (!isClosed(j, i))
                                {
                                    if ((i == m_endX) && (j == m_endY))
                                        pointWeight = 1;
                                    else
                                        pointWeight = CellInfo::pointWeight(m_map,i,j,m_AllowTroughEntity, m_entites);

                                    movementCost = m_mapStatus[QPoint(m_nowX, m_nowY)].getMovementCost() + ((j == m_nowY) || (i == m_nowX) ? m_HVCost : m_DCost) * pointWeight;

                                    if (m_AllowTroughEntity)
                                    {
                                        cellOnEndColumn = (i+j == m_endX+m_endY) ? true : false;
                                        cellOnStartColumn = (i+j == m_startX+m_startY) ? true : false;
                                        cellOnEndLine = (i-j == m_endX-m_endY) ? true : false;
                                        cellOnStartLine = (i-j == m_startX-m_startY) ? true : false;
                                        mp = MapPoint::fromCoords(i,j);

                                        if ((!cellOnEndColumn) && (!cellOnEndLine) || (!cellOnStartColumn) && (!cellOnStartLine))
                                        {
                                            movementCost = movementCost + mp.distanceToCell(m_endPoint);
                                            movementCost = movementCost + mp.distanceToCell(m_startPoint);
                                        }

                                        if ((i == m_endX) || (j == m_endY))
                                            movementCost = movementCost - 3;

                                        if ((cellOnEndColumn) || (cellOnEndLine) || (i + j == m_nowX + m_nowY) || (i - j == m_nowX - m_nowY))
                                            movementCost = movementCost - 2;

                                        if ((i == m_startX) || (j == m_startY))
                                            movementCost = movementCost - 3;

                                        if ((cellOnStartColumn) || (cellOnStartLine))
                                            movementCost = movementCost - 2;

                                        distanceTmpToEnd = mp.distanceToCell(m_endPoint);
                                        if (distanceTmpToEnd < m_distanceToEnd)
                                        {
                                            if ((i == m_endX) || (j == m_endY) || (i + j == m_endX + m_endY) || (i - j == m_endX - m_endY))
                                            {
                                                m_endPointAux = mp;
                                                m_endAuxX = i;
                                                m_endAuxY = j;
                                                m_distanceToEnd = distanceTmpToEnd;
                                            }
                                        }
                                    }

                                    if (isOpened(j,i))
                                    {
                                        if (movementCost < m_mapStatus[QPoint(i,j)].getMovementCost())
                                        {
                                            openSquare(j,i,QPoint(m_nowX, m_nowY),movementCost,99999,true);
                                        }
                                    }
                                    else
                                    {

                                        heuristic = m_HeuristicCost * sqrt((m_endY - j) * (m_endY - j) + (m_endX - i) * (m_endX - i));
                                        openSquare(j,i,QPoint(m_nowX, m_nowY),movementCost,heuristic,false);
                                    }
                                }
                            }
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        endPathFrame();
    }
    else
        endPathFrame();
}

void TestPathfinding::endPathFrame()
{
    QList<MapPoint> returnPathOpti;
    QList<MapPoint> returnPath;
    MapPoint tmpMapPoint;
    int newY = 0;
    int newX = 0;
    int k = 0;
    int kX = 0;
    int kY = 0;
    int nextX = 0;
    int nextY = 0;
    int interX = 0;
    int interY = 0;
    bool pFound = isClosed(m_endY, m_endX);

    if (!pFound)
    {
        m_endY = m_endAuxY;
        m_endX = m_endAuxX;
        m_endPoint = m_endPointAux;
        pFound = true;
        m_movPath.replaceEnd(m_endPoint);
    }

    m_previousCellId = -1;
    if (pFound)
    {
        m_nowY = m_endY;
        m_nowX = m_endX;
        while ((!(m_nowY == m_startY)) || (!(m_nowX == m_startX)))
        {
            returnPath.append(MapPoint::fromCoords(m_nowX,m_nowY));
            newY = m_mapStatus[QPoint(m_nowX, m_nowY)].getParent().y();
            newX = m_mapStatus[QPoint(m_nowX, m_nowY)].getParent().x();
            m_nowY = newY;
            m_nowX = newX;
        }

        returnPath.append(m_startPoint);
        if (m_allowDiag)
        {
            k = 0;
            while (k < returnPath.size())
            {
                returnPathOpti.append(returnPath[k]);
                m_previousCellId = returnPath[k].getCellId();

                if ((returnPath.size() > k+2) && (returnPath[k].distanceToCell(returnPath[k + 2]) == 1) && (!CellInfo::isChangeZone(m_map, returnPath[k].getCellId(),returnPath[k + 1].getCellId())) && (!CellInfo::isChangeZone(m_map, returnPath[k + 1].getCellId(),returnPath[k + 2].getCellId())))
                    k++;
                else if ((returnPath.size() > k+3) && (returnPath[k].distanceToCell(returnPath[k + 3]) == 2))
                {
                    kX = returnPath[k].getX();
                    kY = returnPath[k].getY();
                    nextX = returnPath[k + 3].getX();
                    nextY = returnPath[k + 3].getY();
                    interX = kX + round((nextX - kX) / 2);
                    interY = kY + round((nextY - kY) / 2);
                    if ((CellInfo::pointMov(m_map, interX,interY,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)) && (CellInfo::pointWeight(m_map, interX,interY, m_AllowTroughEntity, m_entites) < 2))
                    {
                        tmpMapPoint = MapPoint::fromCoords(interX,interY);
                        returnPathOpti.append(tmpMapPoint);
                        m_previousCellId = tmpMapPoint.getCellId();
                        k++;
                        k++;
                    }
                }
                else if ((returnPath.size() > k+2) && (returnPath[k].distanceToCell(returnPath[k + 2]) == 2))
                {
                    kX = returnPath[k].getX();
                    kY = returnPath[k].getY();
                    nextX = returnPath[k + 2].getX();
                    nextY = returnPath[k + 2].getY();
                    interX = returnPath[k + 1].getX();
                    interY = returnPath[k + 1].getY();

                    if ((kX + kY == nextX + nextY) && (!(kX - kY == interX - interY)) && (CellInfo::isChangeZone(m_map, MapPoint::fromCoords(kX,kY).getCellId(), MapPoint::fromCoords(interX,interY).getCellId())) && (CellInfo::isChangeZone(m_map, MapPoint::fromCoords(interX,interY).getCellId(),MapPoint::fromCoords(nextX,nextY).getCellId())))
                        k++;

                    else if ((kX - kY == nextX - nextY) && (!(kX - kY == interX - interY)) && (!CellInfo::isChangeZone(m_map, MapPoint::fromCoords(kX,kY).getCellId(),MapPoint::fromCoords(interX,interY).getCellId())) && (!CellInfo::isChangeZone(m_map, MapPoint::fromCoords(interX,interY).getCellId(),MapPoint::fromCoords(nextX,nextY).getCellId())))
                        k++;

                    else if ((kX == nextX) && (!(kX == interX)) && (CellInfo::pointWeight(m_map, kX,interY, m_AllowTroughEntity, m_entites) < 2) && (CellInfo::pointMov(m_map, kX,interY,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)))
                    {
                        tmpMapPoint = MapPoint::fromCoords(kX,interY);
                        returnPathOpti.append(tmpMapPoint);
                        m_previousCellId = tmpMapPoint.getCellId();
                        k++;
                    }
                    else if ((kY == nextY) && (!(kY == interY)) && (CellInfo::pointWeight(m_map, interX,kY, m_AllowTroughEntity, m_entites) < 2) && (CellInfo::pointMov(m_map, interX,kY,m_IsFighting,m_AllowTroughEntity,m_previousCellId, m_entites)))
                    {
                        tmpMapPoint = MapPoint::fromCoords(interX,kY);
                        returnPathOpti.append(tmpMapPoint);
                        m_previousCellId = tmpMapPoint.getCellId();
                        k++;
                    }
                }
                k++;
            }
            returnPath = returnPathOpti;
        }
        QList<MapPoint> result;
        result.reserve(returnPath.size());
        std::reverse_copy(returnPath.begin(), returnPath.end(), std::back_inserter(result));
        movementPathFromArray(result);
    }
}

void TestPathfinding::findPathInternal(QList<CellData> map, MapPoint start, MapPoint end, bool diag)
{
    uint x = 0;
    m_map = map;
    m_start = start;
    m_end = end;
    m_allowDiag = diag;
    m_endPoint = MapPoint::fromCoords(end.getX(), end.getY());
    m_startPoint = MapPoint::fromCoords(start.getX(), start.getY());
    m_endX = end.getX();
    m_endY = end.getY();
    m_startX = start.getX();
    m_startY = start.getY();
    m_endPointAux = m_startPoint;
    m_endAuxX = m_startX;
    m_endAuxY = m_startY;
    m_distanceToEnd = m_startPoint.distanceToCell(m_endPoint);

    int y = TestPathfinding::minY;
    while(y < TestPathfinding::maxY)
    {
        x = TestPathfinding::minX;
        while(x <= TestPathfinding::maxX)
        {

            m_mapStatus[QPoint(x, y)] = CellInfo(0, QPoint(), false, false);
            x++;
        }
        y++;
    }

    openSquare(m_startY, m_startX, QPoint(), 0, -1, false);
    initPathFrame();
}

void TestPathfinding::tracePath(QList<MapPoint> returnPath)
{
    MapPoint point;
    QString cheminEnChaine;
    uint i = 0;

    while(i < returnPath.size())
    {
        point = returnPath[i];
        cheminEnChaine.append(QString(" ") + QString::number(point.getCellId()));
        i++;
    }
}

int TestPathfinding::nearMapObstacle(int x, int y, QList<CellData> map)
{
    int j = 0;
    int distanceMaxToCheck = 2;
    int distanceMin = 42;
    int i = -distanceMaxToCheck;

    while (i < distanceMaxToCheck)
    {
        j = -distanceMaxToCheck;
        while (j < distanceMaxToCheck)
        {
            if (!CellInfo::pointMov(map, x + i, y + j, m_IsFighting,m_AllowTroughEntity, m_previousCellId, m_entites))
                distanceMin = std::min(distanceMin, MapPoint(MapPoint::fromCoords(x,y)).distanceToCell(MapPoint::fromCoords(x + i, y + j)));

            j++;
        }
        i++;
    }
    return distanceMin;
}
