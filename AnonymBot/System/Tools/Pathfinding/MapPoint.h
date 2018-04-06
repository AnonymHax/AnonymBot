#ifndef MAPPOINT_H
#define MAPPOINT_H

#include <QVector>
#include <QPoint>
#include <qmath.h>
#include <QMap>

#include "CellInfo.h"
#include "System/Tools/IO/D2P/D2PManager.h"

enum DirectionEnum
{
    RIGHT_DIR = 0,
    DOWN_RIGHT_DIR = 1,
    DOWN_DIR = 2,
    DOWN_LEFT_DIR = 3,
    LEFT_DIR = 4,
    UP_LEFT_DIR = 5,
    UP_DIR = 6,
    UP_RIGHT_DIR = 7
};

class MapPoint
{
public:
    MapPoint();

    static void init();
    static bool isInMap(int a, int b);
    static MapPoint fromCellId(uint cellId);
    static MapPoint fromCoords(int a, int b);
    static int getOrientationsDistance(int a, int b);

    uint getCellId() const;
    int getX() const;
    int getY() const;

    void setCellId(uint val);
    void setX(int val);
    void setY(int val);

    bool equals(MapPoint point);
    uint distanceTo(MapPoint point);
    int distanceToCell(MapPoint point);
    uint orientationTo(MapPoint point);
    MapPoint getNearestCellInDirection(uint dir);
    uint advancedOrientationTo(MapPoint point, bool diag = true);
    MapPoint getNearestFreeCell(QList<CellData> map, bool diag = true);
    MapPoint getNearestFreeCellInDirection(uint dir, QList<CellData> map, QList<uint> list, bool aBool = true, bool bBool = true, bool cBool = false);


private:
    void setFromCoords();
    void setFromCellId();

    static QPoint vectorRight;
    static QPoint vectorDownRight;
    static QPoint vectorDown;
    static QPoint vectorDownLeft;
    static QPoint vectorLeft;
    static QPoint vectorUpLeft;
    static QPoint vectorUp;
    static QPoint vectorUpRight;
    static uint mapWidth;
    static uint mapHeight;
    static bool isInit;
    static QMap<uint, QPoint> cellPos;

    uint m_CellId;
    int m_X;
    int m_Y;
};

#endif // MAPPOINT_H
