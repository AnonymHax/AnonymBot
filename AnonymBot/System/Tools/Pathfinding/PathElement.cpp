#include "PathElement.h"

PathElement::PathElement()
{
}

PathElement::PathElement(MapPoint point, uint dir)
{
    m_Step = point;
    if (dir != 0)
        m_Orientation = dir;
}

bool PathElement::operator==(PathElement const &right)
{
    if (right.m_Orientation == m_Orientation)
        if (right.m_Step.getCellId() == m_Step.getCellId())
            return true;

    return false;
}

MapPoint PathElement::getStep() const
{
    return m_Step;
}

uint PathElement::getOrientation() const
{
    return m_Orientation;
}

void PathElement::setCellId(uint val)
{
    m_Step.setCellId(val);
}

void PathElement::setStep(MapPoint val)
{
    m_Step = val;
}

void PathElement::setOrientation(uint val)
{
    m_Orientation = val;
}
