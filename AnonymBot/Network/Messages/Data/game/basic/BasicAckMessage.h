#ifndef BASICACKMESSAGE_H
#define BASICACKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicAckMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicAckMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicAckMessage(Reader *param1);
  BasicAckMessage();

  uint seq;
  uint lastPacketId;
};

#endif // BASICACKMESSAGE_H