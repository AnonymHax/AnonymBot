#ifndef EXCHANGEOBJECTMODIFIEDMESSAGE_H
#define EXCHANGEOBJECTMODIFIEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeObjectModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectModifiedMessage(Reader *param1);
  ExchangeObjectModifiedMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // EXCHANGEOBJECTMODIFIEDMESSAGE_H