#ifndef EXCHANGEOBJECTMOVEMESSAGE_H
#define EXCHANGEOBJECTMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectMoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectMoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectMoveMessage(Reader *param1);
  ExchangeObjectMoveMessage();

  uint objectUID;
  int quantity;
};

#endif // EXCHANGEOBJECTMOVEMESSAGE_H