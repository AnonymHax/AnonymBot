#pragma once

#include "System/Tools/IO/Reader.h"

class Map;

class CellData
{
public:
    CellData(int id,  Reader *reader, Map *map);

    int getId() const;
    bool isLos() const;
    bool isWalkable() const;
    bool isNonWalkableDuringFight() const;
    bool isNonWalkableDuringRP() const;
    bool isFarmCell() const;
    bool isVisible() const;
    uint getMapChangeData() const;
    uint getMoveZone() const;
    int getSpeed() const;
    int getFloor() const;
    void setAllowWalk(int w);

private:
    int m_id;
    int m_speed;
    uint m_mapChangeData;
    uint m_moveZone;
    int m_floor;
    int m_arrow;
    int m_allowWalk;

    bool m_walkable;
    bool m_nonWalkableDuringFight;
    bool m_nonWalkableDuringRP;
    bool m_farmCell;
    bool m_visible;
    bool m_los;
};
