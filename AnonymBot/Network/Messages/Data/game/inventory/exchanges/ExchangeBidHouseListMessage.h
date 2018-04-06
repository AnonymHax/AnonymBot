#ifndef EXCHANGEBIDHOUSELISTMESSAGE_H
#define EXCHANGEBIDHOUSELISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseListMessage(Reader *param1);
  ExchangeBidHouseListMessage();

  uint id;
};

#endif // EXCHANGEBIDHOUSELISTMESSAGE_H