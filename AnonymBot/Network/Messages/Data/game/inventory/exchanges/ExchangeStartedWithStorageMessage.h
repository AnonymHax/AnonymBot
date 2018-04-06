#ifndef EXCHANGESTARTEDWITHSTORAGEMESSAGE_H
#define EXCHANGESTARTEDWITHSTORAGEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeStartedMessage.h"

class ExchangeStartedWithStorageMessage : public ExchangeStartedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartedWithStorageMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartedWithStorageMessage(Reader *param1);
  ExchangeStartedWithStorageMessage();

  uint storageMaxSlot;
};

#endif // EXCHANGESTARTEDWITHSTORAGEMESSAGE_H