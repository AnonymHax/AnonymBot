#ifndef PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H
#define PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationCancelledForGuestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationCancelledForGuestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationCancelledForGuestMessage(Reader *param1);
  PartyInvitationCancelledForGuestMessage();

  double cancelerId;
};

#endif // PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H