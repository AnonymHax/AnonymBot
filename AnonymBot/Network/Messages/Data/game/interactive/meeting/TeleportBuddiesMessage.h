#ifndef TELEPORTBUDDIESMESSAGE_H
#define TELEPORTBUDDIESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportBuddiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportBuddiesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportBuddiesMessage(Reader *param1);
  TeleportBuddiesMessage();

  uint dungeonId;
};

#endif // TELEPORTBUDDIESMESSAGE_H