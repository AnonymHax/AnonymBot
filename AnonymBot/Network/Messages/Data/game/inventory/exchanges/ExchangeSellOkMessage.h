#ifndef EXCHANGESELLOKMESSAGE_H
#define EXCHANGESELLOKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeSellOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeSellOkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeSellOkMessage(Reader *param1);
  ExchangeSellOkMessage();
};

#endif // EXCHANGESELLOKMESSAGE_H