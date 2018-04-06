#ifndef EXCHANGEWEIGHTMESSAGE_H
#define EXCHANGEWEIGHTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeWeightMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeWeightMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeWeightMessage(Reader *param1);
  ExchangeWeightMessage();

  uint currentWeight;
  uint maxWeight;
};

#endif // EXCHANGEWEIGHTMESSAGE_H