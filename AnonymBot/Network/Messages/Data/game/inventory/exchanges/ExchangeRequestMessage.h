#ifndef EXCHANGEREQUESTMESSAGE_H
#define EXCHANGEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeRequestMessage(Reader *param1);
  ExchangeRequestMessage();

  int exchangeType;
};

#endif // EXCHANGEREQUESTMESSAGE_H