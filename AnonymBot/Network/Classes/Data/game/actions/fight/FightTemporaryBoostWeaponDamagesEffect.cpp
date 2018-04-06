#include "FightTemporaryBoostWeaponDamagesEffect.h"

void FightTemporaryBoostWeaponDamagesEffect::serialize(Writer *param1)
{
  this->serializeAs_FightTemporaryBoostWeaponDamagesEffect(param1);
}

void FightTemporaryBoostWeaponDamagesEffect::serializeAs_FightTemporaryBoostWeaponDamagesEffect(Writer *param1)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(param1);
  param1->writeShort((short)this->weaponTypeId);
}

void FightTemporaryBoostWeaponDamagesEffect::deserialize(Reader *param1)
{
  this->deserializeAs_FightTemporaryBoostWeaponDamagesEffect(param1);
}

void FightTemporaryBoostWeaponDamagesEffect::deserializeAs_FightTemporaryBoostWeaponDamagesEffect(Reader *param1)
{
  FightTemporaryBoostEffect::deserialize(param1);
  this->weaponTypeId = param1->readShort();
}

FightTemporaryBoostWeaponDamagesEffect::FightTemporaryBoostWeaponDamagesEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT;
}

bool FightTemporaryBoostWeaponDamagesEffect::operator==(const FightTemporaryBoostWeaponDamagesEffect &compared)
{
  if(weaponTypeId == compared.weaponTypeId)
  return true;
  
  return false;
}

