#ifndef EXCHANGEREQUESTONMOUNTSTOCKMESSAGE_H
#define EXCHANGEREQUESTONMOUNTSTOCKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeRequestOnMountStockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeRequestOnMountStockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeRequestOnMountStockMessage(Reader *param1);
  ExchangeRequestOnMountStockMessage();
};

#endif // EXCHANGEREQUESTONMOUNTSTOCKMESSAGE_H