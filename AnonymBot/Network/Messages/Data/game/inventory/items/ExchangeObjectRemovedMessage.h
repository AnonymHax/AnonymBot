#ifndef EXCHANGEOBJECTREMOVEDMESSAGE_H
#define EXCHANGEOBJECTREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectRemovedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectRemovedMessage(Reader *param1);
  ExchangeObjectRemovedMessage();

  uint objectUID;
};

#endif // EXCHANGEOBJECTREMOVEDMESSAGE_H