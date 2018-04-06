#ifndef GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H
#define GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSpellCooldownVariationMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightSpellCooldownVariationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightSpellCooldownVariationMessage(Reader *param1);
  GameActionFightSpellCooldownVariationMessage();

  double targetId;
  uint spellId;
  int value;
};

#endif // GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H