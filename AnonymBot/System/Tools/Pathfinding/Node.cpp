#include "Node.h"
#include <cmath>
#include <math.h>

Node::Node()
{
    m_started = false;
    m_closed = false;
    m_isClosed = false;
}

Node::Node(int cellId, int _x, int _y)
{
    m_x = _x;
    m_y = _y;
    m_cellid = cellId;
}

Node::Node(const Node &right)
{
    m_x = right.m_x;
    m_y = right.m_y;
    m_h = right.m_h;
    m_f = right.m_f;
    m_g = right.m_g;
    m_cellid = right.m_cellid;
    m_parent = right.m_parent;
    m_started = right.m_started;
    m_closed = right.m_closed;
    m_isClosed = right.m_isClosed;
    m_walkable = right.m_walkable;
    n_inClosedList = right.n_inClosedList;
    n_inOpenList = right.n_inOpenList;
    m_orientation = right.m_orientation;
    m_floor = right.m_floor;
}

bool Node::operator==(const Node &right)
{
    if (m_cellid = right.m_cellid)
        return true;

    return false;
}

void Node::setStarted(bool b_start)
{
    m_started = b_start;
}

void Node::setClosed(bool b_close)
{
    m_closed = b_close;
}

void Node::setWalkable(bool b_walkable)
{
    m_walkable = b_walkable;
}

void Node::calculH(Node endNode)
{
    m_h = 10 * (fabs(endNode.getX() - m_x)  + fabs(endNode.getY() - m_y));
}

int Node::getX() const
{
    return m_x;
}

int Node::getY() const
{
    return m_y;
}

void Node::setIsClosed(bool b_ferme)
{
    m_isClosed = b_ferme;
}

int Node::getCellId()const
{
    return m_cellid;
}
void Node::setInOpenList(bool b_inOpenList)
{
    n_inOpenList = b_inOpenList;
}

bool Node::getInOpenList()const
{
    return n_inOpenList;
}
void Node::setInClosedList(bool b_inClosedList)
{
    n_inClosedList = b_inClosedList;
}

bool Node::getInClosedList()const
{
    return n_inClosedList;
}

bool Node::getStarted() const
{
    return m_started;
}

bool Node::getClosed() const
{
    return m_closed;
}

void Node::setParent(int p_id)
{
    m_parent = p_id;
}

int Node::getParent()const
{
    return m_parent;
}

bool Node::getWalkable()const
{
    return m_walkable;
}

void Node::setG(int value)
{
    m_g = value;
}

int Node::getG() const
{
    return m_g;
}

void Node::setF(int value)
{
    m_f = value;
}

int Node::getF()const
{
    return m_f;
}

int Node::getH()const
{
    return m_h;
}

int Node::getOrientation() const
{
    return m_orientation;
}

void Node::setOrientation(int value)
{
    m_orientation = value;
}

int Node::getFloor() const
{
    return m_floor;
}

void Node::setFloor(int floor)
{
    m_floor = floor;
}
