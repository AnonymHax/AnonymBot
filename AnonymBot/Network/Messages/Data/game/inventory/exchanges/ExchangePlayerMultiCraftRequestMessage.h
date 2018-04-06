#ifndef EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H
#define EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeRequestMessage.h"

class ExchangePlayerMultiCraftRequestMessage : public ExchangeRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangePlayerMultiCraftRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangePlayerMultiCraftRequestMessage(Reader *param1);
  ExchangePlayerMultiCraftRequestMessage();

  double target;
  uint skillId;
};

#endif // EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H