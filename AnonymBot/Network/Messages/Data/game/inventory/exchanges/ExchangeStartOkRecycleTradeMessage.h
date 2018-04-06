#ifndef EXCHANGESTARTOKRECYCLETRADEMESSAGE_H
#define EXCHANGESTARTOKRECYCLETRADEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkRecycleTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkRecycleTradeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkRecycleTradeMessage(Reader *param1);
  ExchangeStartOkRecycleTradeMessage();

  uint percentToPrism;
  uint percentToPlayer;
};

#endif // EXCHANGESTARTOKRECYCLETRADEMESSAGE_H