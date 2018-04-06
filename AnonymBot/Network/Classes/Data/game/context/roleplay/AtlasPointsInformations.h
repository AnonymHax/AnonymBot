#ifndef ATLASPOINTSINFORMATIONS_H
#define ATLASPOINTSINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/MapCoordinatesExtended.h"
#include "Network/Classes/Data/game/context/MapCoordinatesExtended.h"

class AtlasPointsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AtlasPointsInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AtlasPointsInformations(Reader *param1);
  AtlasPointsInformations();
  bool operator==(const AtlasPointsInformations &compared);

  uint type;
  QList<QSharedPointer<MapCoordinatesExtended>> coords;
};

#endif // ATLASPOINTSINFORMATIONS_H