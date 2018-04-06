#ifndef EXCHANGESTARTEDBIDBUYERMESSAGE_H
#define EXCHANGESTARTEDBIDBUYERMESSAGE_H

#include "Network/Classes/Data/game/data/items/SellerBuyerDescriptor.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/SellerBuyerDescriptor.h"

class ExchangeStartedBidBuyerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedBidBuyerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedBidBuyerMessage(Reader *param1);
  ExchangeStartedBidBuyerMessage();

  SellerBuyerDescriptor buyerDescriptor;
};

#endif // EXCHANGESTARTEDBIDBUYERMESSAGE_H