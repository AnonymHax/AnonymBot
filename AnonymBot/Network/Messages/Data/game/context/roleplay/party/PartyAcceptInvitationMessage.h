#ifndef PARTYACCEPTINVITATIONMESSAGE_H
#define PARTYACCEPTINVITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyAcceptInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyAcceptInvitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyAcceptInvitationMessage(Reader *param1);
  PartyAcceptInvitationMessage();
};

#endif // PARTYACCEPTINVITATIONMESSAGE_H