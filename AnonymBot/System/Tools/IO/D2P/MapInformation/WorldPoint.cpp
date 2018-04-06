#include "WorldPoint.h"

WorldPoint::WorldPoint()
{

}

WorldPoint::WorldPoint(const uint &id)
{
    setId(id);
}

void WorldPoint::setId(const uint &id)
{
    m_id = id;
    m_worldid = (m_id & 1073479680) >> 18;
    m_x = static_cast<int>(m_id >> 9 & 511);
    m_y = static_cast<int>(m_id & 511);
    if ((m_x & 256) == 256)
    {
        m_x = -(m_x & 255);
    }
    if ((m_y & 256) == 256)
    {
        m_y = -(m_y & 255);
    }
}

uint WorldPoint::getId() const
{
    return m_id;
}

uint WorldPoint::getWorldId() const
{
    return m_worldid;
}

int WorldPoint::getX() const
{
    return m_x;
}

int WorldPoint::getY() const
{
    return m_y;
}
