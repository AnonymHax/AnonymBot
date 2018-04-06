#ifndef EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H
#define EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H

#include "Network/Classes/Data/game/data/items/BidExchangerObjectInfo.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/BidExchangerObjectInfo.h"

class ExchangeTypesItemsExchangerDescriptionForUserMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Reader *param1);
  ExchangeTypesItemsExchangerDescriptionForUserMessage();

  QList<QSharedPointer<BidExchangerObjectInfo>> itemTypeDescriptions;
};

#endif // EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H