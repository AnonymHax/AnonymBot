#ifndef MAPOBSTACLE_H
#define MAPOBSTACLE_H

#include "Network/Classes/AbstractClass.h"

class MapObstacle : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapObstacle(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapObstacle(Reader *param1);
  MapObstacle();
  bool operator==(const MapObstacle &compared);

  uint obstacleCellId;
  uint state;
};

#endif // MAPOBSTACLE_H