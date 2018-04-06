#ifndef EXCHANGEPODSMODIFIEDMESSAGE_H
#define EXCHANGEPODSMODIFIEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangePodsModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangePodsModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangePodsModifiedMessage(Reader *param1);
  ExchangePodsModifiedMessage();

  uint currentWeight;
  uint maxWeight;
};

#endif // EXCHANGEPODSMODIFIEDMESSAGE_H