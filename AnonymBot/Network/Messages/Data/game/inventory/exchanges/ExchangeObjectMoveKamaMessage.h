#ifndef EXCHANGEOBJECTMOVEKAMAMESSAGE_H
#define EXCHANGEOBJECTMOVEKAMAMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectMoveKamaMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectMoveKamaMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectMoveKamaMessage(Reader *param1);
  ExchangeObjectMoveKamaMessage();

  int quantity;
};

#endif // EXCHANGEOBJECTMOVEKAMAMESSAGE_H