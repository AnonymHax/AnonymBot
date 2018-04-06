#ifndef TELEPORTHAVENBAGREQUESTMESSAGE_H
#define TELEPORTHAVENBAGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportHavenBagRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportHavenBagRequestMessage(Reader *param1);
  TeleportHavenBagRequestMessage();

  double guestId;
};

#endif // TELEPORTHAVENBAGREQUESTMESSAGE_H