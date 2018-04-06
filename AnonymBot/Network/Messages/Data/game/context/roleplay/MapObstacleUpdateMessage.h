#ifndef MAPOBSTACLEUPDATEMESSAGE_H
#define MAPOBSTACLEUPDATEMESSAGE_H

#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"

class MapObstacleUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapObstacleUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapObstacleUpdateMessage(Reader *param1);
  MapObstacleUpdateMessage();

  QList<MapObstacle> obstacles;
};

#endif // MAPOBSTACLEUPDATEMESSAGE_H