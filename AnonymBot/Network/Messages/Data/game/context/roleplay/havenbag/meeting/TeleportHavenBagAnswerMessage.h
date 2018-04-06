#ifndef TELEPORTHAVENBAGANSWERMESSAGE_H
#define TELEPORTHAVENBAGANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportHavenBagAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportHavenBagAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportHavenBagAnswerMessage(Reader *param1);
  TeleportHavenBagAnswerMessage();

  bool accept;
};

#endif // TELEPORTHAVENBAGANSWERMESSAGE_H