#ifndef EXCHANGEKAMAMODIFIEDMESSAGE_H
#define EXCHANGEKAMAMODIFIEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeKamaModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeKamaModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeKamaModifiedMessage(Reader *param1);
  ExchangeKamaModifiedMessage();

  uint quantity;
};

#endif // EXCHANGEKAMAMODIFIEDMESSAGE_H