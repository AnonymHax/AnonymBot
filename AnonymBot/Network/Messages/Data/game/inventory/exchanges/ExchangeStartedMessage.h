#ifndef EXCHANGESTARTEDMESSAGE_H
#define EXCHANGESTARTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedMessage(Reader *param1);
  ExchangeStartedMessage();

  int exchangeType;
};

#endif // EXCHANGESTARTEDMESSAGE_H