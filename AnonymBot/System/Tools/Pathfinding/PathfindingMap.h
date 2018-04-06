#ifndef PathfindingMap_H
#define PathfindingMap_H

#include "Public.h"
#include "Pathfinding.h"
#include "MapNode.h"
#include "System/Tools/IO/D2P/D2PManager.h"
#include "System/Tools/IO/D2O/D2OManager.h"
#include "Network/SocketIO.h"

enum class MapSide
{
    TOP, BOTTOM, LEFT, RIGHT, NONE
};

struct ChangeMapRequest
{
    int mapId = 0;
    int cellId = -1;
};

class PathfindingMap : public QThread, public Pathfinding
{

    Q_OBJECT

public:
    PathfindingMap();
    ~PathfindingMap();

    static void initialize();
    static int coordsToMapId(int x, int y, int superAreaID);

    void stopThread();

public slots:
    void requestPath(uint startMapId, uint endMapId, int cellId, SocketIO *sender);

signals:
    void foundPath(QList<ChangeMapRequest> requestedMaps, SocketIO *sender);

private:

    virtual void run();

    QList<ChangeMapRequest> findPath(uint startMapId, uint endMapId, int cell);
    void findNeighboringMaps(MapNode c_node, uint startMapId, uint endMapId);
    void loadMapInList(uint mapId, uint startMapId, uint endMapId);
    void addMap(int map, int cell, MapNode c_MapNode, uint endMapId);
    void sortOpenList();
    int getCellIdFromPoint(int x, int y);
    int processAdjacentCell(uint cellId);
    int checkMap(uint map, uint sideMapId, MapSide mapSide);

    static QMap< int, QMap< QPair<int, int> , int> >  m_mapTranslateTable;
    static QMutex m_mutex;

    uint m_startMapId;
    uint m_endMapId;
    int m_cellId;
    SocketIO *m_sender;

    bool m_running;
    int m_cell;
    bool m_finishSearch;
    QList<MapNode> m_openList;
    QList<int> m_cellsList;
    QMap<uint, MapNode> m_cellPos;
    Map m_currentMap;
};

#endif // PathfindingMap_H
