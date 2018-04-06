#ifndef EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE_H
#define EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemNotInContainer.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeCraftResultMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemNotInContainer.h"

class ExchangeCraftResultWithObjectDescMessage : public ExchangeCraftResultMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftResultWithObjectDescMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftResultWithObjectDescMessage(Reader *param1);
  ExchangeCraftResultWithObjectDescMessage();

  QSharedPointer<ObjectItemNotInContainer> objectInfo;
};

#endif // EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE_H