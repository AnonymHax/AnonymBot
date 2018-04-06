#ifndef EXCHANGEOBJECTSREMOVEDMESSAGE_H
#define EXCHANGEOBJECTSREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectsRemovedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectsRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectsRemovedMessage(Reader *param1);
  ExchangeObjectsRemovedMessage();

  QList<uint> objectUID;
};

#endif // EXCHANGEOBJECTSREMOVEDMESSAGE_H