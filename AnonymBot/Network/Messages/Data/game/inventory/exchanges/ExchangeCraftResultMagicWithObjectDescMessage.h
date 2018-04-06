#ifndef EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H
#define EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemNotInContainer.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeCraftResultWithObjectDescMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemNotInContainer.h"

class ExchangeCraftResultMagicWithObjectDescMessage : public ExchangeCraftResultWithObjectDescMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Reader *param1);
  ExchangeCraftResultMagicWithObjectDescMessage();

  int magicPoolStatus;
};

#endif // EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H