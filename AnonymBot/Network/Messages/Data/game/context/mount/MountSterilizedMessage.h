#ifndef MOUNTSTERILIZEDMESSAGE_H
#define MOUNTSTERILIZEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountSterilizedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountSterilizedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountSterilizedMessage(Reader *param1);
  MountSterilizedMessage();

  int mountId;
};

#endif // MOUNTSTERILIZEDMESSAGE_H