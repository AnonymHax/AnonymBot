#ifndef EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE_H
#define EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeStartedTaxCollectorShopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedTaxCollectorShopMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedTaxCollectorShopMessage(Reader *param1);
  ExchangeStartedTaxCollectorShopMessage();

  QList<QSharedPointer<ObjectItem>> objects;
  uint kamas;
};

#endif // EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE_H