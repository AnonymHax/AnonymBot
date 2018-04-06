#ifndef EXCHANGESTARTOKNPCTRADEMESSAGE_H
#define EXCHANGESTARTOKNPCTRADEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkNpcTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkNpcTradeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkNpcTradeMessage(Reader *param1);
  ExchangeStartOkNpcTradeMessage();

  double npcId;
};

#endif // EXCHANGESTARTOKNPCTRADEMESSAGE_H