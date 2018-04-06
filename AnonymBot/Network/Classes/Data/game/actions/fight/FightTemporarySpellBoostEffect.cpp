#include "FightTemporarySpellBoostEffect.h"

void FightTemporarySpellBoostEffect::serialize(Writer *param1)
{
  this->serializeAs_FightTemporarySpellBoostEffect(param1);
}

void FightTemporarySpellBoostEffect::serializeAs_FightTemporarySpellBoostEffect(Writer *param1)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(param1);
  if(this->boostedSpellId < 0)
  {
    qDebug()<<"ERREUR - FightTemporarySpellBoostEffect -"<<"Forbidden value (" << this->boostedSpellId << ") on element boostedSpellId.";
  }
  else
  {
    param1->writeVarShort((int)this->boostedSpellId);
    return;
  }
}

void FightTemporarySpellBoostEffect::deserialize(Reader *param1)
{
  this->deserializeAs_FightTemporarySpellBoostEffect(param1);
}

void FightTemporarySpellBoostEffect::deserializeAs_FightTemporarySpellBoostEffect(Reader *param1)
{
  FightTemporaryBoostEffect::deserialize(param1);
  this->boostedSpellId = param1->readVarUhShort();
  if(this->boostedSpellId < 0)
  {
    qDebug()<<"ERREUR - FightTemporarySpellBoostEffect -"<<"Forbidden value (" << this->boostedSpellId << ") on element of FightTemporarySpellBoostEffect.boostedSpellId.";
  }
  else
  {
    return;
  }
}

FightTemporarySpellBoostEffect::FightTemporarySpellBoostEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYSPELLBOOSTEFFECT;
}

bool FightTemporarySpellBoostEffect::operator==(const FightTemporarySpellBoostEffect &compared)
{
  if(boostedSpellId == compared.boostedSpellId)
  return true;
  
  return false;
}

