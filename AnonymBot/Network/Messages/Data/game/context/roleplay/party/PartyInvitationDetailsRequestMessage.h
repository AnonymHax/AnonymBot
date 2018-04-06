#ifndef PARTYINVITATIONDETAILSREQUESTMESSAGE_H
#define PARTYINVITATIONDETAILSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationDetailsRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationDetailsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationDetailsRequestMessage(Reader *param1);
  PartyInvitationDetailsRequestMessage();
};

#endif // PARTYINVITATIONDETAILSREQUESTMESSAGE_H