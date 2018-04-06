#ifndef EXCHANGESHOPSTOCKSTARTEDMESSAGE_H
#define EXCHANGESHOPSTOCKSTARTEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"

class ExchangeShopStockStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeShopStockStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeShopStockStartedMessage(Reader *param1);
  ExchangeShopStockStartedMessage();

  QList<QSharedPointer<ObjectItemToSell>> objectsInfos;
};

#endif // EXCHANGESHOPSTOCKSTARTEDMESSAGE_H