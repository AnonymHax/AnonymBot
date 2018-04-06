#ifndef EXCHANGEREQUESTEDMESSAGE_H
#define EXCHANGEREQUESTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeRequestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeRequestedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeRequestedMessage(Reader *param1);
  ExchangeRequestedMessage();

  int exchangeType;
};

#endif // EXCHANGEREQUESTEDMESSAGE_H