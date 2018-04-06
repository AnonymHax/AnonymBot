#ifndef EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE_H
#define EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeStartOkCraftMessage.h"

class ExchangeStartOkCraftWithInformationMessage : public ExchangeStartOkCraftMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkCraftWithInformationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkCraftWithInformationMessage(Reader *param1);
  ExchangeStartOkCraftWithInformationMessage();

  uint skillId;
};

#endif // EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE_H