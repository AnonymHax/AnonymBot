#ifndef GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H
#define GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightReflectDamagesMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightReflectDamagesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightReflectDamagesMessage(Reader *param1);
  GameActionFightReflectDamagesMessage();

  double targetId;
};

#endif // GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE_H