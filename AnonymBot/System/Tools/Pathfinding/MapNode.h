#ifndef MapNode_H
#define MapNode_H

#include <cmath>
#include <iostream>
#include "Public.h"

class MapNode
{
public:
    MapNode();
    MapNode(int mapId, int _x, int _y);
    MapNode(const MapNode &right);
    bool operator==(const MapNode &right);

    void setCellId(int cell);
    int getCellId() const;

    void setStarted(bool b_start);
    bool getStarted()const;

    void setClosed(bool b_close);
    bool getClosed()const;

    void setWalkable(bool b_walkable);
    bool getWalkable()const;

    void calculH(MapNode endMapNode);

    int getH()const;
    int getX() const;
    int getY() const;

    void setFermer(bool b_ferme);

    void setMapId(int id);
    int getMapId() const;

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


private:
    int m_x;
    int m_y;
    int m_h, m_f, m_g;
    int m_mapId;
    int m_parent;
    int m_cellId;
    bool m_started;
    bool m_closed;
    bool m_isClosed;
    bool m_walkable;
    bool n_inClosedList;
    bool n_inOpenList;
};

#endif // MapNode_H
