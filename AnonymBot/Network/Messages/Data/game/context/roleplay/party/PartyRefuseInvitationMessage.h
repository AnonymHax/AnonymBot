#ifndef PARTYREFUSEINVITATIONMESSAGE_H
#define PARTYREFUSEINVITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyRefuseInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyRefuseInvitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyRefuseInvitationMessage(Reader *param1);
  PartyRefuseInvitationMessage();
};

#endif // PARTYREFUSEINVITATIONMESSAGE_H