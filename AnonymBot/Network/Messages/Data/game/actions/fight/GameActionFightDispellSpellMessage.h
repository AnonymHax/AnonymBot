#ifndef GAMEACTIONFIGHTDISPELLSPELLMESSAGE_H
#define GAMEACTIONFIGHTDISPELLSPELLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/fight/GameActionFightDispellMessage.h"

class GameActionFightDispellSpellMessage : public GameActionFightDispellMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDispellSpellMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDispellSpellMessage(Reader *param1);
  GameActionFightDispellSpellMessage();

  uint spellId;
};

#endif // GAMEACTIONFIGHTDISPELLSPELLMESSAGE_H