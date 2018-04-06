#ifndef EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE_H
#define EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeItemAutoCraftStopedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeItemAutoCraftStopedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeItemAutoCraftStopedMessage(Reader *param1);
  ExchangeItemAutoCraftStopedMessage();

  int reason;
};

#endif // EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE_H