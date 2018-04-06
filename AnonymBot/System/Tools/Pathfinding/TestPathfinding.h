#ifndef TESTPATHFINDING_H
#define TESTPATHFINDING_H

#include "CellInfo.h"
#include "MapPoint.h"
#include "PathElement.h"
#include "MovementPath.h"
#include "System/Tools/IO/D2P/D2PManager.h"

#include <QMap>
#include <QList>
#include <QTime>

class TestPathfinding
{
public:
    TestPathfinding();
    static MovementPath findPath(uint mapId, uint _start, uint _end, bool diag = true, bool entity = true, bool isFighting = false, QList<uint> entities = QList<uint>(), bool blockLast = false, bool mount = false);
    MovementPath processFindPath(QList<CellData> map, MapPoint start, MapPoint end, bool diag = true, bool entity = true, bool isFighting = false, QList<uint> entities = QList<uint>(),  bool blockLast = false, bool mount = false);

private:
    static int minX;
    static int maxX;
    static int minY;
    static int maxY;

    void pathFrame();
    uint nearerSquare();
    void endPathFrame();
    void initPathFrame();
    void closeSquare(int x, int y);
    bool isOpened(int y, int x) const;
    bool isClosed(int y, int x) const;
    void tracePath(QList<MapPoint> returnPath);
    void movementPathFromArray(QList<MapPoint> returnPath);
    int nearMapObstacle(int x, int y, QList<CellData> map);
    void findPathInternal(QList<CellData> map, MapPoint start, MapPoint end, bool diag);
    void openSquare(int y, int x, QPoint parent, uint movCost, uint heuristic, bool replace);

    QMap<QPoint, CellInfo> m_mapStatus;
    QList<QPoint> m_openList;
    MovementPath m_movPath;
    QList<CellData> m_map;
    QList<uint> m_entites;
    QTime m_currentTime;
    MapPoint m_start;
    MapPoint m_end;
    MapPoint m_endPoint;
    MapPoint m_startPoint;
    MapPoint m_endPointAux;
    bool m_AllowDiagCornering;
    bool m_enterFrameIsActive;
    bool m_AllowTroughEntity;
    bool m_IsFighting;
    bool m_allowDiag;
    bool m_restart;
    bool m_mount;
    int m_endX;
    int m_endY;
    int m_startX;
    int m_startY;
    int m_endAuxX;
    int m_endAuxY;
    int m_distanceToEnd;
    int m_nowY;
    int m_nowX;
    int m_maxTime;
    int m_previousCellId;
    uint m_HVCost;
    uint m_DCost;
    uint m_HeuristicCost;
};

//QPoint operator for QMap compatibility reasons
bool operator<(const QPoint& lhs, const QPoint& rhs);

#endif // TESTPATHFINDING_H
