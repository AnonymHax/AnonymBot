#ifndef PARTYINVITATIONREQUESTMESSAGE_H
#define PARTYINVITATIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PartyInvitationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationRequestMessage(Reader *param1);
  PartyInvitationRequestMessage();

  QString name;
};

#endif // PARTYINVITATIONREQUESTMESSAGE_H