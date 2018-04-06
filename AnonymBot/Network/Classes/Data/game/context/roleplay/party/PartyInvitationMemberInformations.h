#ifndef PARTYINVITATIONMEMBERINFORMATIONS_H
#define PARTYINVITATIONMEMBERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionBaseInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionBaseInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionBaseInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class PartyInvitationMemberInformations : public CharacterBaseInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationMemberInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationMemberInformations(Reader *param1);
  PartyInvitationMemberInformations();
  bool operator==(const PartyInvitationMemberInformations &compared);

  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  QList<QSharedPointer<PartyCompanionBaseInformations>> companions;
};

#endif // PARTYINVITATIONMEMBERINFORMATIONS_H