#ifndef EXCHANGESELLMESSAGE_H
#define EXCHANGESELLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeSellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeSellMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeSellMessage(Reader *param1);
  ExchangeSellMessage();

  uint objectToSellId;
  uint quantity;
};

#endif // EXCHANGESELLMESSAGE_H