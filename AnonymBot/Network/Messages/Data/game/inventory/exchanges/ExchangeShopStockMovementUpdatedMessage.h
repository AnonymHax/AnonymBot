#ifndef EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H
#define EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"

class ExchangeShopStockMovementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeShopStockMovementUpdatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeShopStockMovementUpdatedMessage(Reader *param1);
  ExchangeShopStockMovementUpdatedMessage();

  QSharedPointer<ObjectItemToSell> objectInfo;
};

#endif // EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H