#ifndef PARTYMEMBERGEOPOSITION_H
#define PARTYMEMBERGEOPOSITION_H

#include "Network/Classes/AbstractClass.h"

class PartyMemberGeoPosition : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyMemberGeoPosition(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyMemberGeoPosition(Reader *param1);
  PartyMemberGeoPosition();
  bool operator==(const PartyMemberGeoPosition &compared);

  uint memberId;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
};

#endif // PARTYMEMBERGEOPOSITION_H