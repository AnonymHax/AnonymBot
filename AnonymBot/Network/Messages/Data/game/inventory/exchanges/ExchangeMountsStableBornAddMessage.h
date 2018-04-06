#ifndef EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H
#define EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeMountsStableAddMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class ExchangeMountsStableBornAddMessage : public ExchangeMountsStableAddMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountsStableBornAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountsStableBornAddMessage(Reader *param1);
  ExchangeMountsStableBornAddMessage();
};

#endif // EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H