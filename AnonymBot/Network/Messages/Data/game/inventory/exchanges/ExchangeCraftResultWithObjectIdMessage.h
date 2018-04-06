#ifndef EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H
#define EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeCraftResultMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeCraftResultMessage.h"

class ExchangeCraftResultWithObjectIdMessage : public ExchangeCraftResultMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftResultWithObjectIdMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftResultWithObjectIdMessage(Reader *param1);
  ExchangeCraftResultWithObjectIdMessage();

  uint objectGenericId;
};

#endif // EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H