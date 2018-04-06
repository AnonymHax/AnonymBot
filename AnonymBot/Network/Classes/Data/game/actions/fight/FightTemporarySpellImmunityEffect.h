#ifndef FIGHTTEMPORARYSPELLIMMUNITYEFFECT_H
#define FIGHTTEMPORARYSPELLIMMUNITYEFFECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"

class FightTemporarySpellImmunityEffect : public AbstractFightDispellableEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTemporarySpellImmunityEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTemporarySpellImmunityEffect(Reader *param1);
  FightTemporarySpellImmunityEffect();
  bool operator==(const FightTemporarySpellImmunityEffect &compared);

  int immuneSpellId;
};

#endif // FIGHTTEMPORARYSPELLIMMUNITYEFFECT_H