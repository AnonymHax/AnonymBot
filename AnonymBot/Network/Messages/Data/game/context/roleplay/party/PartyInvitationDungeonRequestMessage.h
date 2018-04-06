#ifndef PARTYINVITATIONDUNGEONREQUESTMESSAGE_H
#define PARTYINVITATIONDUNGEONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyInvitationRequestMessage.h"

class PartyInvitationDungeonRequestMessage : public PartyInvitationRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationDungeonRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationDungeonRequestMessage(Reader *param1);
  PartyInvitationDungeonRequestMessage();

  uint dungeonId;
};

#endif // PARTYINVITATIONDUNGEONREQUESTMESSAGE_H