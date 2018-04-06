#ifndef GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE_H
#define GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightReduceDamagesMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightReduceDamagesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightReduceDamagesMessage(Reader *param1);
  GameActionFightReduceDamagesMessage();

  double targetId;
  uint amount;
};

#endif // GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE_H