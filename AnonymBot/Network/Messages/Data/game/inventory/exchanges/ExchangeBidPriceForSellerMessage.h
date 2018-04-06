#ifndef EXCHANGEBIDPRICEFORSELLERMESSAGE_H
#define EXCHANGEBIDPRICEFORSELLERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeBidPriceMessage.h"

class ExchangeBidPriceForSellerMessage : public ExchangeBidPriceMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidPriceForSellerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidPriceForSellerMessage(Reader *param1);
  ExchangeBidPriceForSellerMessage();

  bool allIdentical;
  QList<uint> minimalPrices;
};

#endif // EXCHANGEBIDPRICEFORSELLERMESSAGE_H