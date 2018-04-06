#ifndef MOVEMENTPATH_H
#define MOVEMENTPATH_H

#include <QVector>

#include "MapPoint.h"
#include "PathElement.h"

class MovementPath
{
public:
    MovementPath();

    uint getPathTime() const;
    uint getPathSize() const;
    MapPoint getStart() const;
    MapPoint getEnd() const;
    QList<PathElement> getPath() const;

    void setStart(MapPoint val);
    void setEnd(MapPoint val);

    void fill();
    void compress();
    void removeLastCell();
    QVector<uint> getCells();
    void processTime(bool mount);
    void replaceEnd(MapPoint point);
    void addPoint(PathElement element);
    PathElement getPointAtIndex(uint i);
    void deletePoint(uint start, uint end = 1);
    void fillFromCellIds(QVector<uint> cellIds);
    int getCellVelocity(PathElement pE, bool mount, bool walking);

protected:
    uint m_pathTime;
    MapPoint m_Start;
    MapPoint m_End;
    QList<PathElement> m_Path;
};

#endif // MOVEMENTPATH_H
