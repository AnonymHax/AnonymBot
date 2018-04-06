#ifndef PARTYCOMPANIONMEMBERINFORMATIONS_H
#define PARTYCOMPANIONMEMBERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionBaseInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class PartyCompanionMemberInformations : public PartyCompanionBaseInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyCompanionMemberInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyCompanionMemberInformations(Reader *param1);
  PartyCompanionMemberInformations();
  bool operator==(const PartyCompanionMemberInformations &compared);

  uint initiative;
  uint lifePoints;
  uint maxLifePoints;
  uint prospecting;
  uint regenRate;
};

#endif // PARTYCOMPANIONMEMBERINFORMATIONS_H