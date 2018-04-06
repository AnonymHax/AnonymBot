#ifndef PARTYCANCELINVITATIONMESSAGE_H
#define PARTYCANCELINVITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyCancelInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyCancelInvitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyCancelInvitationMessage(Reader *param1);
  PartyCancelInvitationMessage();

  double guestId;
};

#endif // PARTYCANCELINVITATIONMESSAGE_H