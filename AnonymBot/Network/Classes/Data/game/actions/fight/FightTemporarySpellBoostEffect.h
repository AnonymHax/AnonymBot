#ifndef FIGHTTEMPORARYSPELLBOOSTEFFECT_H
#define FIGHTTEMPORARYSPELLBOOSTEFFECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"

class FightTemporarySpellBoostEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTemporarySpellBoostEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTemporarySpellBoostEffect(Reader *param1);
  FightTemporarySpellBoostEffect();
  bool operator==(const FightTemporarySpellBoostEffect &compared);

  uint boostedSpellId;
};

#endif // FIGHTTEMPORARYSPELLBOOSTEFFECT_H