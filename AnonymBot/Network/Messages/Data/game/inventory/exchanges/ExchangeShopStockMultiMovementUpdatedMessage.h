#ifndef EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE_H
#define EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"

class ExchangeShopStockMultiMovementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Reader *param1);
  ExchangeShopStockMultiMovementUpdatedMessage();

  QList<QSharedPointer<ObjectItemToSell>> objectInfoList;
};

#endif // EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE_H