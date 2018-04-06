#include "CellInfo.h"

CellInfo::CellInfo()
{
}

CellInfo::CellInfo(int heuristic, QPoint parent, bool opened, bool closed) :
    m_heuristic(heuristic),
    m_parent(parent),
    m_opened(opened),
    m_closed(closed)
{
}

int CellInfo::getHeuristic() const
{
    return m_heuristic;
}

int CellInfo::getMovementCost() const
{
    return m_movementCost;
}

QPoint CellInfo::getParent() const
{
    return m_parent;
}

bool CellInfo::getOpened() const
{
    return m_opened;
}

bool CellInfo::getClosed() const
{
    return m_closed;
}

void CellInfo::setHeuristic(int val)
{
    m_heuristic = val;
}

void CellInfo::setMovementCost(int val)
{
    m_movementCost = val;
}

void CellInfo::setParent(QPoint val)
{
    m_parent = val;
}

void CellInfo::setOpened(bool val)
{
    m_opened = val;
}

void CellInfo::setClosed(bool val)
{
    m_closed = val;
}

uint CellInfo::coordToCellId(int x, int y)
{
    return (x - y) * MAP_WIDTH + y + (x - y) / 2;
}

bool CellInfo::pointMov(QList<CellData> map, int x, int y, bool isFighting, bool allowThroughEntity, int previousCellId, QList<uint> entities)
{
    int dif = 0;
    bool mov = false;
    if (MapPoint::isInMap(x, y))
    {
        CellData cellData = map[MapPoint::fromCoords(x, y).getCellId()];
        mov = (cellData.isWalkable()) && (!false || !cellData.isNonWalkableDuringFight());

        if ((mov) && (!(previousCellId == -1)) && (!(previousCellId == MapPoint::fromCoords(x, y).getCellId())))
        {
            CellData previousCellData = map[previousCellId];
            dif = abs(abs(cellData.getFloor()) - abs(previousCellData.getFloor()));

            if ((!(previousCellData.getMoveZone() == cellData.getMoveZone())) && (dif > 0) || (previousCellData.getMoveZone() == cellData.getMoveZone()) && (cellData.getMoveZone() == 0) && (dif > TOLERANCE_ELEVATION))
                mov = false;
        }

        if (!allowThroughEntity)
            if (entities.contains(CellInfo::coordToCellId(x, y)))
                return false;
    }
    else
        mov = false;

    return mov;
}

bool CellInfo::pointCanStop(QList<CellData> map, int x, int y, bool allowThroughEntity)
{
    CellData cellData = map[MapPoint::fromCoords(x, y).getCellId()];
    return (CellInfo::pointMov(map, x, y, allowThroughEntity) && !cellData.isNonWalkableDuringRP());
}

float CellInfo::pointWeight(QList<CellData> map, int x, int y, bool allowThroughEntity, QList<uint> entites)
{
    int weight = 1;
    int speed = CellInfo::getCellSpeed(map, MapPoint::fromCoords(x,y).getCellId());

    if (allowThroughEntity)
    {
        if (speed >= 0)
            weight = weight + (5 - speed);
        else
            weight = weight + (11 + abs(speed));

        if (entites.contains(CellInfo::coordToCellId(x, y)))
            weight = 20;
    }
    else
    {
        if (entites.contains(CellInfo::coordToCellId(x, y)))
            weight = weight + 0.3;
        if (entites.contains(CellInfo::coordToCellId(x+1, y)))
            weight = weight + 0.3;
        if (entites.contains(CellInfo::coordToCellId(x, y+1)))
            weight = weight + 0.3;
        if (entites.contains(CellInfo::coordToCellId(x-1, y)))
            weight = weight + 0.3;
        if (entites.contains(CellInfo::coordToCellId(x, y-1)))
            weight = weight + 0.3;
    }

    return weight;
}

bool CellInfo::pointLos(QList<CellData> map, int x, int y, bool allowThroughEntity, QList<uint> entities)
{
    uint cellId = MapPoint::fromCoords(x,y).getCellId();
    bool los = map[cellId].isLos();

    if (!allowThroughEntity)
        if (entities.contains(CellInfo::coordToCellId(x, y)))
            return false;

    return los;
}

int CellInfo::getCellSpeed(QList<CellData> map, uint cellId)
{
    return map[cellId].getSpeed();
}

bool CellInfo::farmCell(QList<CellData> map, int x, int y)
{
    return map[MapPoint::fromCoords(x, y).getCellId()].isFarmCell();
}

bool CellInfo::isChangeZone(QList<CellData> map, uint cell1, uint cell2)
{
    CellData a = map[cell1];
    CellData b = map[cell2];
    uint dif = abs(abs(a.getFloor()) - abs(b.getFloor()));

    if ((a.getMoveZone() == b.getMoveZone()) && (dif == 0))
        return true;

    return false;
}
