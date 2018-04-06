#ifndef EXCHANGESTARTEDBIDSELLERMESSAGE_H
#define EXCHANGESTARTEDBIDSELLERMESSAGE_H

#include "Network/Classes/Data/game/data/items/SellerBuyerDescriptor.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSellInBid.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/SellerBuyerDescriptor.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSellInBid.h"

class ExchangeStartedBidSellerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedBidSellerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedBidSellerMessage(Reader *param1);
  ExchangeStartedBidSellerMessage();

  SellerBuyerDescriptor sellerDescriptor;
  QList<QSharedPointer<ObjectItemToSellInBid>> objectsInfos;
};

#endif // EXCHANGESTARTEDBIDSELLERMESSAGE_H