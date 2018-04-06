#ifndef FIGHTTEMPORARYBOOSTSTATEEFFECT_H
#define FIGHTTEMPORARYBOOSTSTATEEFFECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"

class FightTemporaryBoostStateEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTemporaryBoostStateEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTemporaryBoostStateEffect(Reader *param1);
  FightTemporaryBoostStateEffect();
  bool operator==(const FightTemporaryBoostStateEffect &compared);

  int stateId;
};

#endif // FIGHTTEMPORARYBOOSTSTATEEFFECT_H