#ifndef GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE_H
#define GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSpellImmunityMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightSpellImmunityMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightSpellImmunityMessage(Reader *param1);
  GameActionFightSpellImmunityMessage();

  double targetId;
  uint spellId;
};

#endif // GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE_H