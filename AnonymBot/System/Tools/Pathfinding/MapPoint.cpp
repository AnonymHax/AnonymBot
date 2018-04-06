#include "MapPoint.h"

QPoint MapPoint::vectorRight(1,1);
QPoint MapPoint::vectorDownRight(1,0);
QPoint MapPoint::vectorDown(1,-1);
QPoint MapPoint::vectorDownLeft(0,-1);
QPoint MapPoint::vectorLeft(-1,-1);
QPoint MapPoint::vectorUpLeft(-1,0);
QPoint MapPoint::vectorUp(-1,1);
QPoint MapPoint::vectorUpRight(0,1);
uint MapPoint::mapWidth = 14;
uint MapPoint::mapHeight = 20;
bool MapPoint::isInit = false;
QMap<uint, QPoint> MapPoint::cellPos;

MapPoint::MapPoint()
{
    setCellId(-1);
}

void MapPoint::init()
{
    MapPoint::isInit = true;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    while(e < MapPoint::mapHeight)
    {
        a = 0;
        while(a < MapPoint::mapWidth)
        {
            MapPoint::cellPos[d] = QPoint(b+a, c+a);
            d++;
            a++;
        }
        b++;

        a = 0;
        while(a < MapPoint::mapWidth)
        {
            MapPoint::cellPos[d] = QPoint(b+a, c+a);
            d++;
            a++;
        }
        c--;
        e++;
    }
}

bool MapPoint::isInMap(int a, int b)
{
    return a + b >= 0 && a - b >= 0 && a - b < MapPoint::mapHeight * 2 && a + b < MapPoint::mapWidth * 2;
}

MapPoint MapPoint::fromCellId(uint cellId)
{
    MapPoint a;
    a.setCellId(cellId);
    a.setFromCellId();

    return a;
}

MapPoint MapPoint::fromCoords(int x, int y)
{
    MapPoint a;
    a.setX(x);
    a.setY(y);
    a.setFromCoords();

    return a;
}

int MapPoint::getOrientationsDistance(int a, int b)
{
    return std::min(abs(b - a), abs(8 - b + a));
}

uint MapPoint::getCellId() const
{
    return m_CellId;
}

int MapPoint::getX() const
{
    return m_X;
}

int MapPoint::getY() const
{
    return m_Y;
}

void MapPoint::setCellId(uint val)
{
    m_CellId = val;
}

void MapPoint::setX(int val)
{
    m_X = val;
}

void MapPoint::setY(int val)
{
    m_Y = val;
}

bool MapPoint::equals(MapPoint point)
{
    if (point.getCellId() == m_CellId)
        return true;

    return false;
}

uint MapPoint::distanceTo(MapPoint point)
{
    return sqrt(pow(point.getX() - m_X, 2) + pow(point.getY() - m_Y, 2));
}

int MapPoint::distanceToCell(MapPoint point)
{
    return abs(m_X - point.getX()) + abs(m_Y - point.getY());
}

uint MapPoint::orientationTo(MapPoint point)
{
    uint returnVal = 0;
    if(m_X == point.getX() && m_Y == point.getY())
        return 1;

    QPoint tmpPoint;
    tmpPoint.setX(point.getX() > m_X ? 1 : point.getX() < m_X ? -1 : 0);
    tmpPoint.setY(point.getY() > m_Y ? 1 : point.getY() < m_Y ? -1 : 0);

    if(tmpPoint.x() == MapPoint::vectorRight.x() && tmpPoint.y() == MapPoint::vectorRight.y())
        returnVal = (int)RIGHT_DIR;
    else if(tmpPoint.x() == MapPoint::vectorDownRight.x() && tmpPoint.y() == MapPoint::vectorDownRight.y())
        returnVal = (int)DOWN_RIGHT_DIR;
    else if(tmpPoint.x() == MapPoint::vectorDown.x() && tmpPoint.y() == MapPoint::vectorDown.y())
        returnVal = (int)DOWN_DIR;
    else if(tmpPoint.x() == MapPoint::vectorDownLeft.x() && tmpPoint.y() == MapPoint::vectorDownLeft.y())
        returnVal = (int)DOWN_LEFT_DIR;
    else if(tmpPoint.x() == MapPoint::vectorLeft.x() && tmpPoint.y() == MapPoint::vectorLeft.y())
        returnVal = (int)LEFT_DIR;
    else if(tmpPoint.x() == MapPoint::vectorUpLeft.x() && tmpPoint.y() == MapPoint::vectorUpLeft.y())
        returnVal = (int)UP_LEFT_DIR;
    else if(tmpPoint.x() == MapPoint::vectorUp.x() && tmpPoint.y() == MapPoint::vectorUp.y())
        returnVal = (int)UP_DIR;
    else if(tmpPoint.x() == MapPoint::vectorUpRight.x() && tmpPoint.y() == MapPoint::vectorUpRight.y())
        returnVal = (int)UP_RIGHT_DIR;

    return (uint)returnVal;
}

MapPoint MapPoint::getNearestCellInDirection(uint dir)
{
    MapPoint point;
    switch (dir)
    {
    case 0:
        point = MapPoint::fromCoords(m_X + 1, m_Y + 1);
        break;
    case 1:
        point = MapPoint::fromCoords(m_X + 1, m_Y);
        break;
    case 2:
        point = MapPoint::fromCoords(m_X + 1, m_Y - 1);
        break;
    case 3:
        point = MapPoint::fromCoords(m_X, m_Y - 1);
        break;
    case 4:
        point = MapPoint::fromCoords(m_X - 1, m_Y - 1);
        break;
    case 5:
        point = MapPoint::fromCoords(m_X - 1, m_Y);
        break;
    case 6:
        point = MapPoint::fromCoords(m_X - 1, m_Y + 1);
        break;
    case 7:
        point = MapPoint::fromCoords(m_X, m_Y + 1);
        break;
    }

    if (MapPoint::isInMap(point.getX(), point.getY()))
        return point;
    else
        return MapPoint();
}

uint MapPoint::advancedOrientationTo(MapPoint point, bool diag)
{
    int a = point.getX() - m_X;
    int b = m_Y - point.getY();
    int c = acos(a / sqrt(pow(a, 2) + pow(b, 2))) * 180 / M_PI * (point.getY() > m_Y ? -1 : 1);

    if(diag)
        c = round(c / 90) * 2 + 1;
    else
        c = round(c / 45) + 1;

    if(c < 0)
        c = c + 8;

    return c;
}

MapPoint MapPoint::getNearestFreeCell(QList<CellData> map, bool diag)
{
    MapPoint point;
    uint a = 0;

    while (a < 8)
    {
        QList<uint> empty;
        point = getNearestFreeCellInDirection(a, map, empty, false, diag, false);
        if (point.getCellId() != -1)
            break;

        a++;
    }

    return point;
}

MapPoint MapPoint::getNearestFreeCellInDirection(uint dir, QList<CellData> map, QList<uint> list, bool aBool, bool bBool, bool cBool)
{
    int a = 0;
    int b = 0;
    int c = 0;

    MapPoint point;
    QVector<int> idVector(8);
    QVector<MapPoint> pointVector(8);

    while(a < 8)
    {
        point = getNearestCellInDirection(a);
        if (point.getCellId() != -1 && !list.contains(point.getCellId()))
        {
            b = CellInfo::getCellSpeed(map, point.getCellId());
            if (!CellInfo::pointMov(map, point.getX(), point.getY(), false, bBool, m_CellId, QList<uint>()))
                b = -100;

            idVector[a] = getOrientationsDistance(a, dir) + (!cBool? b >= 0 ? 5 - b : 11 + abs(b) : 0);
        }
        else
            idVector[a] = 1000;

        pointVector[a] = point;
        a++;
    }

    a = 1;
    int d = 0;
    int e = idVector[0];
    point.setCellId(-1);

    while(a < 8)
    {
        c = idVector[a];
        if(c < e && pointVector[a].getCellId() != -1)
        {
            e = c;
            d = a;
        }
        a++;
    }

    point = pointVector[d];
    if(point.getCellId() == -1 && (aBool) && (CellInfo::pointMov(map, m_X, m_Y, false, bBool, m_CellId, QList<uint>())))
        return *this;

    return point;
}

void MapPoint::setFromCoords()
{
    if (!MapPoint::isInit)
        MapPoint::init();

    m_CellId = (m_X - m_Y) * MapPoint::mapWidth + m_Y + (m_X - m_Y) / 2;
}

void MapPoint::setFromCellId()
{
    if (!MapPoint::isInit)
        MapPoint::init();

    QPoint point = MapPoint::cellPos[m_CellId];
    m_X = point.x();
    m_Y = point.y();
}
