#ifndef EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE_H
#define EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectRemovedFromBagMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectRemovedFromBagMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectRemovedFromBagMessage(Reader *param1);
  ExchangeObjectRemovedFromBagMessage();

  uint objectUID;
};

#endif // EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE_H