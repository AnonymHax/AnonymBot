#include "SkillActionDescriptionCollect.h"

void SkillActionDescriptionCollect::serialize(Writer *param1)
{
  this->serializeAs_SkillActionDescriptionCollect(param1);
}

void SkillActionDescriptionCollect::serializeAs_SkillActionDescriptionCollect(Writer *param1)
{
  SkillActionDescriptionTimed::serializeAs_SkillActionDescriptionTimed(param1);
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->min << ") on element min.";
  }
  else
  {
    param1->writeVarShort((int)this->min);
    if(this->max < 0)
    {
      qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->max << ") on element max.";
    }
    else
    {
      param1->writeVarShort((int)this->max);
      return;
    }
  }
}

void SkillActionDescriptionCollect::deserialize(Reader *param1)
{
  this->deserializeAs_SkillActionDescriptionCollect(param1);
}

void SkillActionDescriptionCollect::deserializeAs_SkillActionDescriptionCollect(Reader *param1)
{
  SkillActionDescriptionTimed::deserialize(param1);
  this->min = param1->readVarUhShort();
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->min << ") on element of SkillActionDescriptionCollect.min.";
  }
  else
  {
    this->max = param1->readVarUhShort();
    if(this->max < 0)
    {
      qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->max << ") on element of SkillActionDescriptionCollect.max.";
    }
    else
    {
      return;
    }
  }
}

SkillActionDescriptionCollect::SkillActionDescriptionCollect()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTIONCOLLECT;
}

bool SkillActionDescriptionCollect::operator==(const SkillActionDescriptionCollect &compared)
{
  if(min == compared.min)
  if(max == compared.max)
  return true;
  
  return false;
}

