#ifndef EXCHANGEOFFLINESOLDITEMSMESSAGE_H
#define EXCHANGEOFFLINESOLDITEMSMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantityPrice.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantityPrice.h"

class ExchangeOfflineSoldItemsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeOfflineSoldItemsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeOfflineSoldItemsMessage(Reader *param1);
  ExchangeOfflineSoldItemsMessage();

  QList<ObjectItemGenericQuantityPrice> bidHouseItems;
  QList<ObjectItemGenericQuantityPrice> merchantItems;
};

#endif // EXCHANGEOFFLINESOLDITEMSMESSAGE_H