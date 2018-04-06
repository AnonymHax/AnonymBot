#ifndef TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE_H
#define TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntAvailableRetryCountUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Reader *param1);
  TreasureHuntAvailableRetryCountUpdateMessage();

  uint questType;
  int availableRetryCount;
};

#endif // TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE_H