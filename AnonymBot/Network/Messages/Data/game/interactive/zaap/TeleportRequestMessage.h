#ifndef TELEPORTREQUESTMESSAGE_H
#define TELEPORTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportRequestMessage(Reader *param1);
  TeleportRequestMessage();

  uint teleporterType;
  uint mapId;
};

#endif // TELEPORTREQUESTMESSAGE_H