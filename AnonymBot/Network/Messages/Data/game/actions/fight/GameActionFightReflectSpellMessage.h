#ifndef GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H
#define GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightReflectSpellMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightReflectSpellMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightReflectSpellMessage(Reader *param1);
  GameActionFightReflectSpellMessage();

  double targetId;
};

#endif // GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H