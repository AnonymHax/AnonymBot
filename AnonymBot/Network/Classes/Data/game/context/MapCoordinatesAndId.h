#ifndef MAPCOORDINATESANDID_H
#define MAPCOORDINATESANDID_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/MapCoordinates.h"
#include "Network/Classes/Data/game/context/MapCoordinates.h"

class MapCoordinatesAndId : public MapCoordinates
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapCoordinatesAndId(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapCoordinatesAndId(Reader *param1);
  MapCoordinatesAndId();
  bool operator==(const MapCoordinatesAndId &compared);

  int mapId;
};

#endif // MAPCOORDINATESANDID_H