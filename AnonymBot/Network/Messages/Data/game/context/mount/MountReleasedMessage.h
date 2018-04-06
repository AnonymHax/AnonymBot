#ifndef MOUNTRELEASEDMESSAGE_H
#define MOUNTRELEASEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountReleasedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountReleasedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountReleasedMessage(Reader *param1);
  MountReleasedMessage();

  int mountId;
};

#endif // MOUNTRELEASEDMESSAGE_H