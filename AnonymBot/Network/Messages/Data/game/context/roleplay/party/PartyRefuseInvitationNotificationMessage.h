#ifndef PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H
#define PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyRefuseInvitationNotificationMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyRefuseInvitationNotificationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyRefuseInvitationNotificationMessage(Reader *param1);
  PartyRefuseInvitationNotificationMessage();

  double guestId;
};

#endif // PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H