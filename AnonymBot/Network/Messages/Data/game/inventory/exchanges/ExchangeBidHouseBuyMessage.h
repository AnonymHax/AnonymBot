#ifndef EXCHANGEBIDHOUSEBUYMESSAGE_H
#define EXCHANGEBIDHOUSEBUYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseBuyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseBuyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseBuyMessage(Reader *param1);
  ExchangeBidHouseBuyMessage();

  uint uid;
  uint qty;
  uint price;
};

#endif // EXCHANGEBIDHOUSEBUYMESSAGE_H