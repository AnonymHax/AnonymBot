#ifndef EXCHANGEWAITINGRESULTMESSAGE_H
#define EXCHANGEWAITINGRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeWaitingResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeWaitingResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeWaitingResultMessage(Reader *param1);
  ExchangeWaitingResultMessage();

  bool bwait;
};

#endif // EXCHANGEWAITINGRESULTMESSAGE_H