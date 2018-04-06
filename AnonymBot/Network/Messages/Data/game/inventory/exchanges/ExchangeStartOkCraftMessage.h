#ifndef EXCHANGESTARTOKCRAFTMESSAGE_H
#define EXCHANGESTARTOKCRAFTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkCraftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkCraftMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkCraftMessage(Reader *param1);
  ExchangeStartOkCraftMessage();
};

#endif // EXCHANGESTARTOKCRAFTMESSAGE_H