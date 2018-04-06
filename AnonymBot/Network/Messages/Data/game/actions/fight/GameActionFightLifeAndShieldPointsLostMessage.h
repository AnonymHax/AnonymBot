#ifndef GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_H
#define GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/fight/GameActionFightLifePointsLostMessage.h"

class GameActionFightLifeAndShieldPointsLostMessage : public GameActionFightLifePointsLostMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightLifeAndShieldPointsLostMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightLifeAndShieldPointsLostMessage(Reader *param1);
  GameActionFightLifeAndShieldPointsLostMessage();

  uint shieldLoss;
};

#endif // GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_H