#ifndef TELEPORTTOBUDDYANSWERMESSAGE_H
#define TELEPORTTOBUDDYANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportToBuddyAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportToBuddyAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportToBuddyAnswerMessage(Reader *param1);
  TeleportToBuddyAnswerMessage();

  uint dungeonId;
  double buddyId;
  bool accept;
};

#endif // TELEPORTTOBUDDYANSWERMESSAGE_H