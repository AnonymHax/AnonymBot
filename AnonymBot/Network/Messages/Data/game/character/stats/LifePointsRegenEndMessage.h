#ifndef LIFEPOINTSREGENENDMESSAGE_H
#define LIFEPOINTSREGENENDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/character/stats/UpdateLifePointsMessage.h"

class LifePointsRegenEndMessage : public UpdateLifePointsMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LifePointsRegenEndMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LifePointsRegenEndMessage(Reader *param1);
  LifePointsRegenEndMessage();

  uint lifePointsGained;
};

#endif // LIFEPOINTSREGENENDMESSAGE_H