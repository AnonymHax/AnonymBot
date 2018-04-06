#ifndef CHANNELENABLINGMESSAGE_H
#define CHANNELENABLINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChannelEnablingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChannelEnablingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChannelEnablingMessage(Reader *param1);
  ChannelEnablingMessage();

  uint channel;
  bool enable;
};

#endif // CHANNELENABLINGMESSAGE_H