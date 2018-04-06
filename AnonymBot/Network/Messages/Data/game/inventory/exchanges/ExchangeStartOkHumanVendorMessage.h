#ifndef EXCHANGESTARTOKHUMANVENDORMESSAGE_H
#define EXCHANGESTARTOKHUMANVENDORMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemToSellInHumanVendorShop.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSellInHumanVendorShop.h"

class ExchangeStartOkHumanVendorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkHumanVendorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkHumanVendorMessage(Reader *param1);
  ExchangeStartOkHumanVendorMessage();

  double sellerId;
  QList<QSharedPointer<ObjectItemToSellInHumanVendorShop>> objectsInfos;
};

#endif // EXCHANGESTARTOKHUMANVENDORMESSAGE_H