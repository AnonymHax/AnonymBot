#ifndef GAMEFIGHTSPELLCOOLDOWN_H
#define GAMEFIGHTSPELLCOOLDOWN_H

#include "Network/Classes/AbstractClass.h"

class GameFightSpellCooldown : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightSpellCooldown(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightSpellCooldown(Reader *param1);
  GameFightSpellCooldown();
  bool operator==(const GameFightSpellCooldown &compared);

  int spellId;
  uint cooldown;
};

#endif // GAMEFIGHTSPELLCOOLDOWN_H