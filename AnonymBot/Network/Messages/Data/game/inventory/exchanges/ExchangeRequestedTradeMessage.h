#ifndef EXCHANGEREQUESTEDTRADEMESSAGE_H
#define EXCHANGEREQUESTEDTRADEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeRequestedMessage.h"

class ExchangeRequestedTradeMessage : public ExchangeRequestedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeRequestedTradeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeRequestedTradeMessage(Reader *param1);
  ExchangeRequestedTradeMessage();

  double source;
  double target;
};

#endif // EXCHANGEREQUESTEDTRADEMESSAGE_H