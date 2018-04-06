#ifndef TELEPORTONSAMEMAPMESSAGE_H
#define TELEPORTONSAMEMAPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportOnSameMapMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportOnSameMapMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportOnSameMapMessage(Reader *param1);
  TeleportOnSameMapMessage();

  double targetId;
  uint cellId;
};

#endif // TELEPORTONSAMEMAPMESSAGE_H