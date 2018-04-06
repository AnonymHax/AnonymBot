#ifndef MAPCOORDINATESEXTENDED_H
#define MAPCOORDINATESEXTENDED_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/MapCoordinatesAndId.h"
#include "Network/Classes/Data/game/context/MapCoordinatesAndId.h"

class MapCoordinatesExtended : public MapCoordinatesAndId
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapCoordinatesExtended(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapCoordinatesExtended(Reader *param1);
  MapCoordinatesExtended();
  bool operator==(const MapCoordinatesExtended &compared);

  uint subAreaId;
};

#endif // MAPCOORDINATESEXTENDED_H