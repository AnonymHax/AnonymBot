#ifndef TELEPORTTOBUDDYCLOSEMESSAGE_H
#define TELEPORTTOBUDDYCLOSEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportToBuddyCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportToBuddyCloseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportToBuddyCloseMessage(Reader *param1);
  TeleportToBuddyCloseMessage();

  uint dungeonId;
  double buddyId;
};

#endif // TELEPORTTOBUDDYCLOSEMESSAGE_H