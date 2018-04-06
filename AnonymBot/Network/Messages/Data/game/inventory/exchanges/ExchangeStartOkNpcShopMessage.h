#ifndef EXCHANGESTARTOKNPCSHOPMESSAGE_H
#define EXCHANGESTARTOKNPCSHOPMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemToSellInNpcShop.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSellInNpcShop.h"

class ExchangeStartOkNpcShopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkNpcShopMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkNpcShopMessage(Reader *param1);
  ExchangeStartOkNpcShopMessage();

  double npcSellerId;
  uint tokenId;
  QList<QSharedPointer<ObjectItemToSellInNpcShop>> objectsInfos;
};

#endif // EXCHANGESTARTOKNPCSHOPMESSAGE_H