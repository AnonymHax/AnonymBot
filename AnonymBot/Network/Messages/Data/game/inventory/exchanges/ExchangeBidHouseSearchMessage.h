#ifndef EXCHANGEBIDHOUSESEARCHMESSAGE_H
#define EXCHANGEBIDHOUSESEARCHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseSearchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseSearchMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseSearchMessage(Reader *param1);
  ExchangeBidHouseSearchMessage();

  uint type;
  uint genId;
};

#endif // EXCHANGEBIDHOUSESEARCHMESSAGE_H