#ifndef EXCHANGEREQUESTONSHOPSTOCKMESSAGE_H
#define EXCHANGEREQUESTONSHOPSTOCKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeRequestOnShopStockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeRequestOnShopStockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeRequestOnShopStockMessage(Reader *param1);
  ExchangeRequestOnShopStockMessage();
};

#endif // EXCHANGEREQUESTONSHOPSTOCKMESSAGE_H