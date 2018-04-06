#include "HumanOptionSkillUse.h"

void HumanOptionSkillUse::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionSkillUse(param1);
}

void HumanOptionSkillUse::serializeAs_HumanOptionSkillUse(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  else
  {
    param1->writeVarInt((int)this->elementId);
    if(this->skillId < 0)
    {
      qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
    }
    else
    {
      param1->writeVarShort((int)this->skillId);
      if(this->skillEndTime < -9.007199254740992E15 || this->skillEndTime > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillEndTime << ") on element skillEndTime.";
      }
      else
      {
        param1->writeDouble(this->skillEndTime);
        return;
      }
    }
  }
}

void HumanOptionSkillUse::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionSkillUse(param1);
}

void HumanOptionSkillUse::deserializeAs_HumanOptionSkillUse(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->elementId = param1->readVarUhInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->elementId << ") on element of HumanOptionSkillUse.elementId.";
  }
  else
  {
    this->skillId = param1->readVarUhShort();
    if(this->skillId < 0)
    {
      qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillId << ") on element of HumanOptionSkillUse.skillId.";
    }
    else
    {
      this->skillEndTime = param1->readDouble();
      if(this->skillEndTime < -9.007199254740992E15 || this->skillEndTime > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillEndTime << ") on element of HumanOptionSkillUse.skillEndTime.";
      }
      else
      {
        return;
      }
    }
  }
}

HumanOptionSkillUse::HumanOptionSkillUse()
{
  m_types<<ClassEnum::HUMANOPTIONSKILLUSE;
}

bool HumanOptionSkillUse::operator==(const HumanOptionSkillUse &compared)
{
  if(elementId == compared.elementId)
  if(skillId == compared.skillId)
  if(skillEndTime == compared.skillEndTime)
  return true;
  
  return false;
}

