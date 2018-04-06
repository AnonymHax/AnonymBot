#ifndef EXCHANGESTARTOKRUNESTRADEMESSAGE_H
#define EXCHANGESTARTOKRUNESTRADEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkRunesTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkRunesTradeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkRunesTradeMessage(Reader *param1);
  ExchangeStartOkRunesTradeMessage();
};

#endif // EXCHANGESTARTOKRUNESTRADEMESSAGE_H