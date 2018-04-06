#ifndef EXCHANGESTARTEDWITHPODSMESSAGE_H
#define EXCHANGESTARTEDWITHPODSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeStartedMessage.h"

class ExchangeStartedWithPodsMessage : public ExchangeStartedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedWithPodsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedWithPodsMessage(Reader *param1);
  ExchangeStartedWithPodsMessage();

  double firstCharacterId;
  uint firstCharacterCurrentWeight;
  uint firstCharacterMaxWeight;
  double secondCharacterId;
  uint secondCharacterCurrentWeight;
  uint secondCharacterMaxWeight;
};

#endif // EXCHANGESTARTEDWITHPODSMESSAGE_H