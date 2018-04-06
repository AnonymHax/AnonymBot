#ifndef EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H
#define EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantity.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantity.h"

class ExchangeBidHouseUnsoldItemsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseUnsoldItemsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseUnsoldItemsMessage(Reader *param1);
  ExchangeBidHouseUnsoldItemsMessage();

  QList<ObjectItemGenericQuantity> items;
};

#endif // EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H