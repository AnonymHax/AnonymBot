#ifndef CHANNELENABLINGCHANGEMESSAGE_H
#define CHANNELENABLINGCHANGEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChannelEnablingChangeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChannelEnablingChangeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChannelEnablingChangeMessage(Reader *param1);
  ChannelEnablingChangeMessage();

  uint channel;
  bool enable;
};

#endif // CHANNELENABLINGCHANGEMESSAGE_H