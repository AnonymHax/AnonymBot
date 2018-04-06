#ifndef EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeBidHouseInListAddedMessage.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ExchangeBidHouseInListUpdatedMessage : public ExchangeBidHouseInListAddedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseInListUpdatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseInListUpdatedMessage(Reader *param1);
  ExchangeBidHouseInListUpdatedMessage();
};

#endif // EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H