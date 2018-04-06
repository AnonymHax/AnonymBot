#ifndef EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H
#define EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeObjectModifiedInBagMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectModifiedInBagMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectModifiedInBagMessage(Reader *param1);
  ExchangeObjectModifiedInBagMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H