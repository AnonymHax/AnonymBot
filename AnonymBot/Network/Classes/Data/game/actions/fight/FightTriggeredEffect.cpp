#include "FightTriggeredEffect.h"

void FightTriggeredEffect::serialize(Writer *param1)
{
  this->serializeAs_FightTriggeredEffect(param1);
}

void FightTriggeredEffect::serializeAs_FightTriggeredEffect(Writer *param1)
{
  AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(param1);
  param1->writeInt((int)this->param1);
  param1->writeInt((int)this->param2);
  param1->writeInt((int)this->param3);
  param1->writeShort((short)this->delay);
}

void FightTriggeredEffect::deserialize(Reader *param1)
{
  this->deserializeAs_FightTriggeredEffect(param1);
}

void FightTriggeredEffect::deserializeAs_FightTriggeredEffect(Reader *param1)
{
  AbstractFightDispellableEffect::deserialize(param1);
  this->param1 = param1->readInt();
  this->param2 = param1->readInt();
  this->param3 = param1->readInt();
  this->delay = param1->readShort();
}

FightTriggeredEffect::FightTriggeredEffect()
{
  m_types<<ClassEnum::FIGHTTRIGGEREDEFFECT;
}

bool FightTriggeredEffect::operator==(const FightTriggeredEffect &compared)
{
  if(param1 == compared.param1)
  if(param2 == compared.param2)
  if(param3 == compared.param3)
  if(delay == compared.delay)
  return true;
  
  return false;
}

