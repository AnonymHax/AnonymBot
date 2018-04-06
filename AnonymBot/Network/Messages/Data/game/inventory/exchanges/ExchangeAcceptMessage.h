#ifndef EXCHANGEACCEPTMESSAGE_H
#define EXCHANGEACCEPTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeAcceptMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeAcceptMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeAcceptMessage(Reader *param1);
  ExchangeAcceptMessage();
};

#endif // EXCHANGEACCEPTMESSAGE_H