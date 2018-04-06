#ifndef EXCHANGEBIDHOUSEITEMADDOKMESSAGE_H
#define EXCHANGEBIDHOUSEITEMADDOKMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemToSellInBid.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSellInBid.h"

class ExchangeBidHouseItemAddOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseItemAddOkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseItemAddOkMessage(Reader *param1);
  ExchangeBidHouseItemAddOkMessage();

  QSharedPointer<ObjectItemToSellInBid> itemInfo;
};

#endif // EXCHANGEBIDHOUSEITEMADDOKMESSAGE_H