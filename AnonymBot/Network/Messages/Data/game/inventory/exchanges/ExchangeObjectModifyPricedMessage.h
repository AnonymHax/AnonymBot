#ifndef EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H
#define EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMovePricedMessage.h"

class ExchangeObjectModifyPricedMessage : public ExchangeObjectMovePricedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectModifyPricedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectModifyPricedMessage(Reader *param1);
  ExchangeObjectModifyPricedMessage();
};

#endif // EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H