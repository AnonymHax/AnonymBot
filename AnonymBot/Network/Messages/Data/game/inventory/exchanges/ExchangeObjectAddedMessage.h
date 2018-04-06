#ifndef EXCHANGEOBJECTADDEDMESSAGE_H
#define EXCHANGEOBJECTADDEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeObjectAddedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectAddedMessage(Reader *param1);
  ExchangeObjectAddedMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // EXCHANGEOBJECTADDEDMESSAGE_H