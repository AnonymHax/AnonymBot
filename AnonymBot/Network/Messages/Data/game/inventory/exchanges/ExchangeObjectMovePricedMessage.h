#ifndef EXCHANGEOBJECTMOVEPRICEDMESSAGE_H
#define EXCHANGEOBJECTMOVEPRICEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMoveMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMoveMessage.h"

class ExchangeObjectMovePricedMessage : public ExchangeObjectMoveMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectMovePricedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectMovePricedMessage(Reader *param1);
  ExchangeObjectMovePricedMessage();

  uint price;
};

#endif // EXCHANGEOBJECTMOVEPRICEDMESSAGE_H