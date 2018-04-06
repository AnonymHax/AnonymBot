#ifndef GAMEACTIONFIGHTDROPCHARACTERMESSAGE_H
#define GAMEACTIONFIGHTDROPCHARACTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDropCharacterMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDropCharacterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDropCharacterMessage(Reader *param1);
  GameActionFightDropCharacterMessage();

  double targetId;
  int cellId;
};

#endif // GAMEACTIONFIGHTDROPCHARACTERMESSAGE_H