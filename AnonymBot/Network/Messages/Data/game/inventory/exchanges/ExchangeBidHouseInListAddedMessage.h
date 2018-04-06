#ifndef EXCHANGEBIDHOUSEINLISTADDEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTADDEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class ExchangeBidHouseInListAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseInListAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseInListAddedMessage(Reader *param1);
  ExchangeBidHouseInListAddedMessage();

  int itemUID;
  int objGenericId;
  QList<QSharedPointer<ObjectEffect>> effects;
  QList<uint> prices;
};

#endif // EXCHANGEBIDHOUSEINLISTADDEDMESSAGE_H