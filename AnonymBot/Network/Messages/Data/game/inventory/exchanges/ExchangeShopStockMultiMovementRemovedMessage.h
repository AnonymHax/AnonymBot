#ifndef EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE_H
#define EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeShopStockMultiMovementRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeShopStockMultiMovementRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeShopStockMultiMovementRemovedMessage(Reader *param1);
  ExchangeShopStockMultiMovementRemovedMessage();

  QList<uint> objectIdList;
};

#endif // EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE_H