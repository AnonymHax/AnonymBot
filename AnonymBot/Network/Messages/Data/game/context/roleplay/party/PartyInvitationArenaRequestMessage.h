#ifndef PARTYINVITATIONARENAREQUESTMESSAGE_H
#define PARTYINVITATIONARENAREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyInvitationRequestMessage.h"

class PartyInvitationArenaRequestMessage : public PartyInvitationRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationArenaRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationArenaRequestMessage(Reader *param1);
  PartyInvitationArenaRequestMessage();
};

#endif // PARTYINVITATIONARENAREQUESTMESSAGE_H