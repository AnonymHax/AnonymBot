#ifndef MAPCOORDINATES_H
#define MAPCOORDINATES_H

#include "Network/Classes/AbstractClass.h"

class MapCoordinates : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapCoordinates(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapCoordinates(Reader *param1);
  MapCoordinates();
  bool operator==(const MapCoordinates &compared);

  int worldX;
  int worldY;
};

#endif // MAPCOORDINATES_H