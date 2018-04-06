#ifndef GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_H
#define GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightLifePointsLostMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightLifePointsLostMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightLifePointsLostMessage(Reader *param1);
  GameActionFightLifePointsLostMessage();

  double targetId;
  uint loss;
  uint permanentDamages;
};

#endif // GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_H