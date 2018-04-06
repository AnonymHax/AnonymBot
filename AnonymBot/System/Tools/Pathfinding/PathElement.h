#ifndef PATHELEMENT_H
#define PATHELEMENT_H

#include "MapPoint.h"

class PathElement
{
public:
    PathElement();
    PathElement(MapPoint point, uint dir = 0);
    bool operator==(PathElement const &right);

    MapPoint getStep() const;
    uint getOrientation() const;

    void setCellId(uint val);
    void setStep(MapPoint val);
    void setOrientation(uint val);

private:
    MapPoint m_Step;
    uint m_Orientation;
};

#endif // PATHELEMENT_H
