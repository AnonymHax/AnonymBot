#ifndef EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H
#define EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeCraftResultWithObjectIdMessage.h"

class ExchangeCraftInformationObjectMessage : public ExchangeCraftResultWithObjectIdMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftInformationObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftInformationObjectMessage(Reader *param1);
  ExchangeCraftInformationObjectMessage();

  double playerId;
};

#endif // EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H