#ifndef PARTYINVITATIONDUNGEONDETAILSMESSAGE_H
#define PARTYINVITATIONDUNGEONDETAILSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyInvitationDetailsMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"

class PartyInvitationDungeonDetailsMessage : public PartyInvitationDetailsMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationDungeonDetailsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationDungeonDetailsMessage(Reader *param1);
  PartyInvitationDungeonDetailsMessage();

  uint dungeonId;
  QList<bool> playersDungeonReady;
};

#endif // PARTYINVITATIONDUNGEONDETAILSMESSAGE_H