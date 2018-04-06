#ifndef EXCHANGEREADYMESSAGE_H
#define EXCHANGEREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeReadyMessage(Reader *param1);
  ExchangeReadyMessage();

  bool ready;
  uint step;
};

#endif // EXCHANGEREADYMESSAGE_H