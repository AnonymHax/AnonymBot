#ifndef EXCHANGEOBJECTPUTINBAGMESSAGE_H
#define EXCHANGEOBJECTPUTINBAGMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeObjectPutInBagMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectPutInBagMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectPutInBagMessage(Reader *param1);
  ExchangeObjectPutInBagMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // EXCHANGEOBJECTPUTINBAGMESSAGE_H