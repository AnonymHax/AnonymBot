#ifndef MOUNTUNSETMESSAGE_H
#define MOUNTUNSETMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountUnSetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountUnSetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountUnSetMessage(Reader *param1);
  MountUnSetMessage();
};

#endif // MOUNTUNSETMESSAGE_H