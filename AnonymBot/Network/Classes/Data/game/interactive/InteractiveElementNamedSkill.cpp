#include "InteractiveElementNamedSkill.h"

void InteractiveElementNamedSkill::serialize(Writer *param1)
{
  this->serializeAs_InteractiveElementNamedSkill(param1);
}

void InteractiveElementNamedSkill::serializeAs_InteractiveElementNamedSkill(Writer *param1)
{
  InteractiveElementSkill::serializeAs_InteractiveElementSkill(param1);
  if(this->nameId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementNamedSkill -"<<"Forbidden value (" << this->nameId << ") on element nameId.";
  }
  else
  {
    param1->writeVarInt((int)this->nameId);
    return;
  }
}

void InteractiveElementNamedSkill::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveElementNamedSkill(param1);
}

void InteractiveElementNamedSkill::deserializeAs_InteractiveElementNamedSkill(Reader *param1)
{
  InteractiveElementSkill::deserialize(param1);
  this->nameId = param1->readVarUhInt();
  if(this->nameId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementNamedSkill -"<<"Forbidden value (" << this->nameId << ") on element of InteractiveElementNamedSkill.nameId.";
  }
  else
  {
    return;
  }
}

InteractiveElementNamedSkill::InteractiveElementNamedSkill()
{
  m_types<<ClassEnum::INTERACTIVEELEMENTNAMEDSKILL;
}

bool InteractiveElementNamedSkill::operator==(const InteractiveElementNamedSkill &compared)
{
  if(nameId == compared.nameId)
  return true;
  
  return false;
}

