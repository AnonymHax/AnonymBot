#ifndef EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE_H
#define EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkMulticraftCrafterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkMulticraftCrafterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkMulticraftCrafterMessage(Reader *param1);
  ExchangeStartOkMulticraftCrafterMessage();

  uint skillId;
};

#endif // EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE_H