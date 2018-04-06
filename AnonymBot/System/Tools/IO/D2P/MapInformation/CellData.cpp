#include "CellData.h"
#include "System/Tools/IO/D2P/MapInformation/Map.h"

CellData::CellData(int id, Reader *reader, Map *map)
{
    m_id = id;
    m_allowWalk = 0;
    m_floor = reader->readByte() * 10;

    if(map->getMapVersion() >= 9)
    {
        short tmpBytes = reader->readShort();
        m_walkable = (tmpBytes & 1) == 0;
        m_nonWalkableDuringFight = (tmpBytes& 2) != 0;
        m_nonWalkableDuringRP = (tmpBytes & 4) != 0;
        m_los = (tmpBytes & 8) == 0;
        m_visible = (tmpBytes & 64) != 0;
        m_farmCell = (tmpBytes & 128) != 0;


        if(map->getMapVersion() >= 10)
        {
            bool havenbagCell = (tmpBytes & 256) != 0;

            if((tmpBytes & 512) != 0)
                map->addTopArrowCell(id);

            if((tmpBytes & 1024) != 0)
                map->addBottomArrowCell(id);

            if((tmpBytes & 2048) != 0)
                map->addRightArrowCell(id);

            if((tmpBytes & 4096) != 0)
                map->addLeftArrowCell(id);
        }

        else
        {
            if((tmpBytes & 256) != 0)
                map->addTopArrowCell(id);

            if((tmpBytes & 512) != 0)
                map->addBottomArrowCell(id);

            if((tmpBytes & 1024) != 0)
                map->addRightArrowCell(id);

            if((tmpBytes & 2048) != 0)
                map->addLeftArrowCell(id);
        }
    }

    else
    {
        uchar losmov = reader->readUByte();
        m_los = (losmov & 2) >> 1 == 1;
        m_walkable = (losmov & 1) == 1;
        m_visible = (losmov & 64) >> 6 == 1;
        m_farmCell = (losmov & 32) >> 5 == 1;
        m_nonWalkableDuringRP = (losmov & 128) >> 7 == 1;
        m_nonWalkableDuringFight = (losmov & 4) >> 2 == 1;
    }

    m_speed = reader->readByte();
    m_mapChangeData = reader->readUByte();

    if(map->getMapVersion() > 5)
        m_moveZone = reader->readUByte();

    if(map->getMapVersion() > 7 && map->getMapVersion() < 9)
    {
        int tmpBits = reader->readByte();
        m_arrow = 15 & tmpBits;

        if(!((m_arrow & 1) == 0))
            map->addTopArrowCell(id);

        if(!((m_arrow & 2) == 0))
            map->addBottomArrowCell(id);

        if(!((m_arrow & 4) == 0))
            map->addRightArrowCell(id);

        if(!((m_arrow & 8) == 0))
            map->addLeftArrowCell(id);
    }

}

int CellData::getId() const
{
    return m_id;
}

bool CellData::isLos() const
{
    return m_los;
}

bool CellData::isWalkable() const
{
    if (m_allowWalk == 1)
        return true;
    else if (m_allowWalk == 2)
        return false;
    else
        return m_walkable;
}

bool CellData::isNonWalkableDuringFight() const
{
    return m_nonWalkableDuringFight;
}

bool CellData::isNonWalkableDuringRP() const
{
    return m_nonWalkableDuringRP;
}

bool CellData::isFarmCell() const
{
    return m_farmCell;
}

bool CellData::isVisible() const
{
    return m_visible;
}

uint CellData::getMapChangeData() const
{
    return m_mapChangeData;
}

int CellData::getSpeed() const
{
    return m_speed;
}

int CellData::getFloor() const
{
    return m_floor;
}

uint CellData::getMoveZone() const
{
    return m_moveZone;
}

void CellData::setAllowWalk(int w)
{
    m_allowWalk = w;
}
