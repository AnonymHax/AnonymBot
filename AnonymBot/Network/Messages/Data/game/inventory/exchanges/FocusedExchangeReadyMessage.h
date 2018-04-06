#ifndef FOCUSEDEXCHANGEREADYMESSAGE_H
#define FOCUSEDEXCHANGEREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeReadyMessage.h"

class FocusedExchangeReadyMessage : public ExchangeReadyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FocusedExchangeReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FocusedExchangeReadyMessage(Reader *param1);
  FocusedExchangeReadyMessage();

  uint focusActionId;
};

#endif // FOCUSEDEXCHANGEREADYMESSAGE_H