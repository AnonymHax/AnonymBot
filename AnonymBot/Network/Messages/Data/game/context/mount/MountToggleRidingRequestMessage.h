#ifndef MOUNTTOGGLERIDINGREQUESTMESSAGE_H
#define MOUNTTOGGLERIDINGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountToggleRidingRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountToggleRidingRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountToggleRidingRequestMessage(Reader *param1);
  MountToggleRidingRequestMessage();
};

#endif // MOUNTTOGGLERIDINGREQUESTMESSAGE_H