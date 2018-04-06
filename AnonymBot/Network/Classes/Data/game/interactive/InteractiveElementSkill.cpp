#include "InteractiveElementSkill.h"

void InteractiveElementSkill::serialize(Writer *param1)
{
  this->serializeAs_InteractiveElementSkill(param1);
}

void InteractiveElementSkill::serializeAs_InteractiveElementSkill(Writer *param1)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  else
  {
    param1->writeVarInt((int)this->skillId);
    if(this->skillInstanceUid < 0)
    {
      qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillInstanceUid << ") on element skillInstanceUid.";
    }
    else
    {
      param1->writeInt((int)this->skillInstanceUid);
      return;
    }
  }
}

void InteractiveElementSkill::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveElementSkill(param1);
}

void InteractiveElementSkill::deserializeAs_InteractiveElementSkill(Reader *param1)
{
  this->skillId = param1->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillId << ") on element of InteractiveElementSkill.skillId.";
  }
  else
  {
    this->skillInstanceUid = param1->readInt();
    if(this->skillInstanceUid < 0)
    {
      qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillInstanceUid << ") on element of InteractiveElementSkill.skillInstanceUid.";
    }
    else
    {
      return;
    }
  }
}

InteractiveElementSkill::InteractiveElementSkill()
{
  m_types<<ClassEnum::INTERACTIVEELEMENTSKILL;
}

bool InteractiveElementSkill::operator==(const InteractiveElementSkill &compared)
{
  if(skillId == compared.skillId)
  if(skillInstanceUid == compared.skillInstanceUid)
  return true;
  
  return false;
}

