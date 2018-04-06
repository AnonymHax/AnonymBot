#ifndef FIGHTTEMPORARYBOOSTEFFECT_H
#define FIGHTTEMPORARYBOOSTEFFECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"

class FightTemporaryBoostEffect : public AbstractFightDispellableEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTemporaryBoostEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTemporaryBoostEffect(Reader *param1);
  FightTemporaryBoostEffect();
  bool operator==(const FightTemporaryBoostEffect &compared);

  int delta;
};

#endif // FIGHTTEMPORARYBOOSTEFFECT_H