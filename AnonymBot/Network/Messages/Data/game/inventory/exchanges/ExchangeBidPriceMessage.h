#ifndef EXCHANGEBIDPRICEMESSAGE_H
#define EXCHANGEBIDPRICEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidPriceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidPriceMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidPriceMessage(Reader *param1);
  ExchangeBidPriceMessage();

  uint genericId;
  int averagePrice;
};

#endif // EXCHANGEBIDPRICEMESSAGE_H