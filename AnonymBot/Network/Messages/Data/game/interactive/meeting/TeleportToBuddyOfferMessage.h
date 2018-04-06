#ifndef TELEPORTTOBUDDYOFFERMESSAGE_H
#define TELEPORTTOBUDDYOFFERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportToBuddyOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportToBuddyOfferMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportToBuddyOfferMessage(Reader *param1);
  TeleportToBuddyOfferMessage();

  uint dungeonId;
  double buddyId;
  uint timeLeft;
};

#endif // TELEPORTTOBUDDYOFFERMESSAGE_H