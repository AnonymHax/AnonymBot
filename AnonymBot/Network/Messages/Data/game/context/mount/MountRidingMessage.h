#ifndef MOUNTRIDINGMESSAGE_H
#define MOUNTRIDINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountRidingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountRidingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountRidingMessage(Reader *param1);
  MountRidingMessage();

  bool isRiding;
};

#endif // MOUNTRIDINGMESSAGE_H