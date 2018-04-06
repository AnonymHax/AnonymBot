#ifndef GAMEACTIONFIGHTCARRYCHARACTERMESSAGE_H
#define GAMEACTIONFIGHTCARRYCHARACTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightCarryCharacterMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightCarryCharacterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightCarryCharacterMessage(Reader *param1);
  GameActionFightCarryCharacterMessage();

  double targetId;
  int cellId;
};

#endif // GAMEACTIONFIGHTCARRYCHARACTERMESSAGE_H