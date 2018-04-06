#ifndef GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_H
#define GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightLifePointsGainMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightLifePointsGainMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightLifePointsGainMessage(Reader *param1);
  GameActionFightLifePointsGainMessage();

  double targetId;
  uint delta;
};

#endif // GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_H