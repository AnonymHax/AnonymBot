#ifndef EXCHANGEOBJECTSADDEDMESSAGE_H
#define EXCHANGEOBJECTSADDEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeObjectsAddedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectsAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectsAddedMessage(Reader *param1);
  ExchangeObjectsAddedMessage();

  QList<QSharedPointer<ObjectItem>> object;
};

#endif // EXCHANGEOBJECTSADDEDMESSAGE_H