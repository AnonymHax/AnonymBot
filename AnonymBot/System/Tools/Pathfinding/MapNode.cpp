#include "MapNode.h"
#include <cmath>
#include <math.h>

bool MapNode::operator==(const MapNode &right)
{
    if (m_mapId == right.getMapId())
        if (m_parent == right.getParent())
            return true;

    return false;
}


MapNode::MapNode()
{
    m_started = false;
    m_closed = false;
    m_isClosed = false;
}

MapNode::MapNode(int mapId, int _x, int _y)
{
    m_x = _x;
    m_y = _y;
    m_mapId = mapId;
    m_h = 0;
    m_g = 0;
    m_f = 0;
}

MapNode::MapNode(const MapNode &right)
{
    m_x = right.m_x;
    m_y = right.m_y;
    m_mapId = right.m_mapId;
    m_h = right.m_h;
    m_f = right.m_f;
    m_g = right.m_g;
    m_cellId = right.m_cellId;
    m_parent = right.m_parent;
    m_started = right.m_started;
    m_closed = right.m_closed;
    m_isClosed = right.m_isClosed;
    m_walkable = right.m_walkable;
    n_inClosedList = right.n_inClosedList;
    n_inOpenList = right.n_inOpenList;
}

void MapNode::setCellId(int cell)
{
    m_cellId = cell;
}

int MapNode::getCellId() const
{
    return m_cellId;
}

void MapNode::setStarted(bool b_start)
{
    m_started = b_start;
}

void MapNode::setClosed(bool b_close)
{
    m_closed = b_close;
}

void MapNode::setWalkable(bool b_walkable)
{
   m_walkable = b_walkable;
}

void MapNode::calculH(MapNode endMapNode)
{
    m_h = 10 * (fabs(endMapNode.getX() - m_x)  + fabs(endMapNode.getY() - m_y));
}

int MapNode::getX() const
{
    return m_x;
}

int MapNode::getY() const
{
    return m_y;
}

void MapNode::setFermer(bool b_ferme)
{
    m_isClosed = b_ferme;
}

void MapNode::setMapId(int id)
{
    m_mapId = id;
}

int MapNode::getMapId()const
{
    return m_mapId;
}
void MapNode::setInOpenList(bool b_inOpenList)
{
    n_inOpenList = b_inOpenList;
}

bool MapNode::getInOpenList()const
{
    return n_inOpenList;
}
void MapNode::setInClosedList(bool b_inClosedList)
{
    n_inClosedList = b_inClosedList;
}

bool MapNode::getInClosedList()const
{
    return n_inClosedList;
}

bool MapNode::getStarted() const
{
    return m_started;
}

bool MapNode::getClosed() const
{
    return m_closed;
}

void MapNode::setParent(int p_id)
{
    m_parent = p_id;
}

int MapNode::getParent()const
{
    return m_parent;
}

bool MapNode::getWalkable()const
{
    return m_walkable;
}

void MapNode::setG(int value)
{
    m_g = value;
}

int MapNode::getG() const
{
    return m_g;
}

void MapNode::setF(int value)
{
    m_f = value;
}

int MapNode::getF()const
{
    return m_f;
}

int MapNode::getH()const
{
    return m_h;
}
