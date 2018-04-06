#ifndef GAMEACTIONFIGHTKILLMESSAGE_H
#define GAMEACTIONFIGHTKILLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightKillMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightKillMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightKillMessage(Reader *param1);
  GameActionFightKillMessage();

  double targetId;
};

#endif // GAMEACTIONFIGHTKILLMESSAGE_H