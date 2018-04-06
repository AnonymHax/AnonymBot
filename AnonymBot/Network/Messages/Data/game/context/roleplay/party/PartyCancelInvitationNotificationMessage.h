#ifndef PARTYCANCELINVITATIONNOTIFICATIONMESSAGE_H
#define PARTYCANCELINVITATIONNOTIFICATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyCancelInvitationNotificationMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyCancelInvitationNotificationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyCancelInvitationNotificationMessage(Reader *param1);
  PartyCancelInvitationNotificationMessage();

  double cancelerId;
  double guestId;
};

#endif // PARTYCANCELINVITATIONNOTIFICATIONMESSAGE_H