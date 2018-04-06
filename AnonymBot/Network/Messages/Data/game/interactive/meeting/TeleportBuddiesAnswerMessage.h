#ifndef TELEPORTBUDDIESANSWERMESSAGE_H
#define TELEPORTBUDDIESANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportBuddiesAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportBuddiesAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportBuddiesAnswerMessage(Reader *param1);
  TeleportBuddiesAnswerMessage();

  bool accept;
};

#endif // TELEPORTBUDDIESANSWERMESSAGE_H