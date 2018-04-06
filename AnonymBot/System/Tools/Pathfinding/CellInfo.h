#ifndef CELLINFO_H
#define CELLINFO_H

#include "MapPoint.h"
#include <QPoint>
#include <QList>

#include "System/Tools/IO/D2P/D2PManager.h"

#define MAP_WIDTH 14
#define MAP_HEIGHT 20
#define TOLERANCE_ELEVATION 11

class CellInfo
{
public:
    CellInfo();
    CellInfo(int heuristic, QPoint parent, bool opened, bool closed);

    static bool pointMov(QList<CellData> map, int x, int y, bool isFighting, bool allowThroughEntity = true, int previousCellId = -1, QList<uint> entities = QList<uint>());
    static float pointWeight(QList<CellData> map, int x, int y, bool allowThroughEntity = true, QList<uint> entites = QList<uint>());
    static bool pointLos(QList<CellData> map, int x, int y, bool allowThroughEntity = true, QList<uint> entities = QList<uint>());
    static bool pointCanStop(QList<CellData> map, int x, int y, bool allowThroughEntity = true);
    static bool isChangeZone(QList<CellData> map, uint cell1, uint cell2);
    static int getCellSpeed(QList<CellData> map, uint cellId);
    static bool farmCell(QList<CellData> map, int x, int y);
    static uint coordToCellId(int x, int y);

    int getHeuristic() const;
    int getMovementCost() const;
    QPoint getParent() const;
    bool getOpened() const;
    bool getClosed() const;

    void setHeuristic(int val);
    void setMovementCost(int val);
    void setParent(QPoint val);
    void setOpened(bool val);
    void setClosed(bool val);

private:
    int m_heuristic;
    int m_movementCost;
    QPoint m_parent;
    bool m_opened;
    bool m_closed;
};

#endif // CELLINFO_H
