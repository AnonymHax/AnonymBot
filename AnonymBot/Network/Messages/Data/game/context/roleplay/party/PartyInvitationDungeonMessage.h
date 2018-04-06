#ifndef PARTYINVITATIONDUNGEONMESSAGE_H
#define PARTYINVITATIONDUNGEONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyInvitationMessage.h"

class PartyInvitationDungeonMessage : public PartyInvitationMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationDungeonMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationDungeonMessage(Reader *param1);
  PartyInvitationDungeonMessage();

  uint dungeonId;
};

#endif // PARTYINVITATIONDUNGEONMESSAGE_H