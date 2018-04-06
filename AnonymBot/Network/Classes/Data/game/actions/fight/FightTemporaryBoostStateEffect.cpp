#include "FightTemporaryBoostStateEffect.h"

void FightTemporaryBoostStateEffect::serialize(Writer *param1)
{
  this->serializeAs_FightTemporaryBoostStateEffect(param1);
}

void FightTemporaryBoostStateEffect::serializeAs_FightTemporaryBoostStateEffect(Writer *param1)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(param1);
  param1->writeShort((short)this->stateId);
}

void FightTemporaryBoostStateEffect::deserialize(Reader *param1)
{
  this->deserializeAs_FightTemporaryBoostStateEffect(param1);
}

void FightTemporaryBoostStateEffect::deserializeAs_FightTemporaryBoostStateEffect(Reader *param1)
{
  FightTemporaryBoostEffect::deserialize(param1);
  this->stateId = param1->readShort();
}

FightTemporaryBoostStateEffect::FightTemporaryBoostStateEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYBOOSTSTATEEFFECT;
}

bool FightTemporaryBoostStateEffect::operator==(const FightTemporaryBoostStateEffect &compared)
{
  if(stateId == compared.stateId)
  return true;
  
  return false;
}

