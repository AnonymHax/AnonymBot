#include "FightTemporarySpellImmunityEffect.h"

void FightTemporarySpellImmunityEffect::serialize(Writer *param1)
{
  this->serializeAs_FightTemporarySpellImmunityEffect(param1);
}

void FightTemporarySpellImmunityEffect::serializeAs_FightTemporarySpellImmunityEffect(Writer *param1)
{
  AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(param1);
  param1->writeInt((int)this->immuneSpellId);
}

void FightTemporarySpellImmunityEffect::deserialize(Reader *param1)
{
  this->deserializeAs_FightTemporarySpellImmunityEffect(param1);
}

void FightTemporarySpellImmunityEffect::deserializeAs_FightTemporarySpellImmunityEffect(Reader *param1)
{
  AbstractFightDispellableEffect::deserialize(param1);
  this->immuneSpellId = param1->readInt();
}

FightTemporarySpellImmunityEffect::FightTemporarySpellImmunityEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYSPELLIMMUNITYEFFECT;
}

bool FightTemporarySpellImmunityEffect::operator==(const FightTemporarySpellImmunityEffect &compared)
{
  if(immuneSpellId == compared.immuneSpellId)
  return true;
  
  return false;
}

