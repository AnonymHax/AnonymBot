#ifndef ENABLEDCHANNELSMESSAGE_H
#define ENABLEDCHANNELSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EnabledChannelsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EnabledChannelsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EnabledChannelsMessage(Reader *param1);
  EnabledChannelsMessage();

  QList<uint> channels;
  QList<uint> disallowed;
};

#endif // ENABLEDCHANNELSMESSAGE_H