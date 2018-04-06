#ifndef ONCONNECTIONEVENTMESSAGE_H
#define ONCONNECTIONEVENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class OnConnectionEventMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_OnConnectionEventMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_OnConnectionEventMessage(Reader *param1);
  OnConnectionEventMessage();

  uint eventType;
};

#endif // ONCONNECTIONEVENTMESSAGE_H