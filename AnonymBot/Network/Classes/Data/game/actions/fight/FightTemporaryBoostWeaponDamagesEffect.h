#ifndef FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H
#define FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"

class FightTemporaryBoostWeaponDamagesEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTemporaryBoostWeaponDamagesEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTemporaryBoostWeaponDamagesEffect(Reader *param1);
  FightTemporaryBoostWeaponDamagesEffect();
  bool operator==(const FightTemporaryBoostWeaponDamagesEffect &compared);

  int weaponTypeId;
};

#endif // FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H