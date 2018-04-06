#ifndef GAMEACTIONFIGHTDEATHMESSAGE_H
#define GAMEACTIONFIGHTDEATHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDeathMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDeathMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDeathMessage(Reader *param1);
  GameActionFightDeathMessage();

  double targetId;
};

#endif // GAMEACTIONFIGHTDEATHMESSAGE_H