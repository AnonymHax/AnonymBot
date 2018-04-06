#ifndef EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE_H
#define EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeShopStockMovementRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeShopStockMovementRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeShopStockMovementRemovedMessage(Reader *param1);
  ExchangeShopStockMovementRemovedMessage();

  uint objectId;
};

#endif // EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE_H