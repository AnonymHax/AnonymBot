#ifndef EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE_H
#define EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkMulticraftCustomerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkMulticraftCustomerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkMulticraftCustomerMessage(Reader *param1);
  ExchangeStartOkMulticraftCustomerMessage();

  uint skillId;
  uint crafterJobLevel;
};

#endif // EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE_H