#ifndef TELEPORTBUDDIESREQUESTEDMESSAGE_H
#define TELEPORTBUDDIESREQUESTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportBuddiesRequestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportBuddiesRequestedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportBuddiesRequestedMessage(Reader *param1);
  TeleportBuddiesRequestedMessage();

  uint dungeonId;
  double inviterId;
  QList<double> invalidBuddiesIds;
};

#endif // TELEPORTBUDDIESREQUESTEDMESSAGE_H