#ifndef GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_H
#define GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightTeleportOnSameMapMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightTeleportOnSameMapMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightTeleportOnSameMapMessage(Reader *param1);
  GameActionFightTeleportOnSameMapMessage();

  double targetId;
  int cellId;
};

#endif // GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_H