#ifndef EXCHANGEBIDHOUSEPRICEMESSAGE_H
#define EXCHANGEBIDHOUSEPRICEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHousePriceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHousePriceMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHousePriceMessage(Reader *param1);
  ExchangeBidHousePriceMessage();

  uint genId;
};

#endif // EXCHANGEBIDHOUSEPRICEMESSAGE_H