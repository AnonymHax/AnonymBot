#ifndef MOUNTSTERILIZEREQUESTMESSAGE_H
#define MOUNTSTERILIZEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountSterilizeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountSterilizeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountSterilizeRequestMessage(Reader *param1);
  MountSterilizeRequestMessage();
};

#endif // MOUNTSTERILIZEREQUESTMESSAGE_H