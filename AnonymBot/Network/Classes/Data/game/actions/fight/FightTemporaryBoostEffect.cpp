#include "FightTemporaryBoostEffect.h"

void FightTemporaryBoostEffect::serialize(Writer *param1)
{
  this->serializeAs_FightTemporaryBoostEffect(param1);
}

void FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(Writer *param1)
{
  AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(param1);
  param1->writeShort((short)this->delta);
}

void FightTemporaryBoostEffect::deserialize(Reader *param1)
{
  this->deserializeAs_FightTemporaryBoostEffect(param1);
}

void FightTemporaryBoostEffect::deserializeAs_FightTemporaryBoostEffect(Reader *param1)
{
  AbstractFightDispellableEffect::deserialize(param1);
  this->delta = param1->readShort();
}

FightTemporaryBoostEffect::FightTemporaryBoostEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYBOOSTEFFECT;
}

bool FightTemporaryBoostEffect::operator==(const FightTemporaryBoostEffect &compared)
{
  if(delta == compared.delta)
  return true;
  
  return false;
}

