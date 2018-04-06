#ifndef EXCHANGEBIDHOUSEBUYRESULTMESSAGE_H
#define EXCHANGEBIDHOUSEBUYRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseBuyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseBuyResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseBuyResultMessage(Reader *param1);
  ExchangeBidHouseBuyResultMessage();

  uint uid;
  bool bought;
};

#endif // EXCHANGEBIDHOUSEBUYRESULTMESSAGE_H