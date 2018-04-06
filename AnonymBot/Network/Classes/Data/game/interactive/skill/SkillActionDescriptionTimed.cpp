#include "SkillActionDescriptionTimed.h"

void SkillActionDescriptionTimed::serialize(Writer *param1)
{
  this->serializeAs_SkillActionDescriptionTimed(param1);
}

void SkillActionDescriptionTimed::serializeAs_SkillActionDescriptionTimed(Writer *param1)
{
  SkillActionDescription::serializeAs_SkillActionDescription(param1);
  if(this->time < 0 || this->time > 255)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionTimed -"<<"Forbidden value (" << this->time << ") on element time.";
  }
  else
  {
    param1->writeByte(this->time);
    return;
  }
}

void SkillActionDescriptionTimed::deserialize(Reader *param1)
{
  this->deserializeAs_SkillActionDescriptionTimed(param1);
}

void SkillActionDescriptionTimed::deserializeAs_SkillActionDescriptionTimed(Reader *param1)
{
  SkillActionDescription::deserialize(param1);
  this->time = param1->readUByte();
  if(this->time < 0 || this->time > 255)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionTimed -"<<"Forbidden value (" << this->time << ") on element of SkillActionDescriptionTimed.time.";
  }
  else
  {
    return;
  }
}

SkillActionDescriptionTimed::SkillActionDescriptionTimed()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTIONTIMED;
}

bool SkillActionDescriptionTimed::operator==(const SkillActionDescriptionTimed &compared)
{
  if(time == compared.time)
  return true;
  
  return false;
}

