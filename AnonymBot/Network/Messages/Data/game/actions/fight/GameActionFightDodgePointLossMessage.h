#ifndef GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H
#define GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDodgePointLossMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDodgePointLossMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDodgePointLossMessage(Reader *param1);
  GameActionFightDodgePointLossMessage();

  double targetId;
  uint amount;
};

#endif // GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H