#ifndef GAMEACTIONFIGHTTHROWCHARACTERMESSAGE_H
#define GAMEACTIONFIGHTTHROWCHARACTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightThrowCharacterMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightThrowCharacterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightThrowCharacterMessage(Reader *param1);
  GameActionFightThrowCharacterMessage();

  double targetId;
  int cellId;
};

#endif // GAMEACTIONFIGHTTHROWCHARACTERMESSAGE_H