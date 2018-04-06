#ifndef EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H
#define EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ExchangeStartedMountStockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedMountStockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedMountStockMessage(Reader *param1);
  ExchangeStartedMountStockMessage();

  QList<QSharedPointer<ObjectItem>> objectsInfos;
};

#endif // EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H