#include "SkillActionDescription.h"

void SkillActionDescription::serialize(Writer *param1)
{
  this->serializeAs_SkillActionDescription(param1);
}

void SkillActionDescription::serializeAs_SkillActionDescription(Writer *param1)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescription -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  else
  {
    param1->writeVarShort((int)this->skillId);
    return;
  }
}

void SkillActionDescription::deserialize(Reader *param1)
{
  this->deserializeAs_SkillActionDescription(param1);
}

void SkillActionDescription::deserializeAs_SkillActionDescription(Reader *param1)
{
  this->skillId = param1->readVarUhShort();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescription -"<<"Forbidden value (" << this->skillId << ") on element of SkillActionDescription.skillId.";
  }
  else
  {
    return;
  }
}

SkillActionDescription::SkillActionDescription()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTION;
}

bool SkillActionDescription::operator==(const SkillActionDescription &compared)
{
  if(skillId == compared.skillId)
  return true;
  
  return false;
}

