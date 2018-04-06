#ifndef EXCHANGEOBJECTMESSAGE_H
#define EXCHANGEOBJECTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectMessage(Reader *param1);
  ExchangeObjectMessage();

  bool remote;
};

#endif // EXCHANGEOBJECTMESSAGE_H