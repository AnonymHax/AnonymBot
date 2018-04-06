#ifndef EXCHANGEPLAYERREQUESTMESSAGE_H
#define EXCHANGEPLAYERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeRequestMessage.h"

class ExchangePlayerRequestMessage : public ExchangeRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangePlayerRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangePlayerRequestMessage(Reader *param1);
  ExchangePlayerRequestMessage();

  double target;
};

#endif // EXCHANGEPLAYERREQUESTMESSAGE_H