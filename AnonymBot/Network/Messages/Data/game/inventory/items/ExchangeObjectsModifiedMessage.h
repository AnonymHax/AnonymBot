#ifndef EXCHANGEOBJECTSMODIFIEDMESSAGE_H
#define EXCHANGEOBJECTSMODIFIEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeObjectsModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectsModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectsModifiedMessage(Reader *param1);
  ExchangeObjectsModifiedMessage();

  QList<QSharedPointer<ObjectItem>> object;
};

#endif // EXCHANGEOBJECTSMODIFIEDMESSAGE_H