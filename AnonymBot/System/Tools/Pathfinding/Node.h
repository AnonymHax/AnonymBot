#ifndef NODE_H
#define NODE_H

#include <cmath>
#include <iostream>
#include "Public.h"

class Node
{
public:
    Node();
    Node(int cellId, int _x, int _y);
    Node(const Node &right);
    bool operator==(const Node &right);

    void setStarted(bool b_start);
    bool getStarted()const;

    void setClosed(bool b_close);
    bool getClosed()const;

    void setWalkable(bool b_walkable);
    bool getWalkable()const;

    void calculH(Node endNode);

    int getH()const;
    int getX() const;
    int getY() const;

    void setIsClosed(bool b_ferme);

    int getCellId() const;

    void setInOpenList(bool b_inOpenList);
    bool getInOpenList()const;

    void setInClosedList(bool b_inClosedList);
    bool getInClosedList()const;

    void setParent(int p_id);
    int getParent()const;

    void setG(int value);
    int getG()const;

    void setF(int value);
    int getF()const;

    void setOrientation(int value);
    int getOrientation() const;

    void setFloor(int floor);
    int getFloor() const;

private:
    int m_orientation;
    int m_x;
    int m_y;
    int m_h, m_f, m_g;
    int m_cellid;
    int m_parent;
    int m_floor;
    bool m_started;
    bool m_closed;
    bool m_isClosed;
    bool m_walkable;
    bool n_inClosedList;
    bool n_inOpenList;
};

#endif // NODE_H
