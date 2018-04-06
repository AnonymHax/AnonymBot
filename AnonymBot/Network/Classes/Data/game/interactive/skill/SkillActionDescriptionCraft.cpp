#include "SkillActionDescriptionCraft.h"

void SkillActionDescriptionCraft::serialize(Writer *param1)
{
  this->serializeAs_SkillActionDescriptionCraft(param1);
}

void SkillActionDescriptionCraft::serializeAs_SkillActionDescriptionCraft(Writer *param1)
{
  SkillActionDescription::serializeAs_SkillActionDescription(param1);
  if(this->probability < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCraft -"<<"Forbidden value (" << this->probability << ") on element probability.";
  }
  else
  {
    param1->writeByte(this->probability);
    return;
  }
}

void SkillActionDescriptionCraft::deserialize(Reader *param1)
{
  this->deserializeAs_SkillActionDescriptionCraft(param1);
}

void SkillActionDescriptionCraft::deserializeAs_SkillActionDescriptionCraft(Reader *param1)
{
  SkillActionDescription::deserialize(param1);
  this->probability = param1->readByte();
  if(this->probability < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCraft -"<<"Forbidden value (" << this->probability << ") on element of SkillActionDescriptionCraft.probability.";
  }
  else
  {
    return;
  }
}

SkillActionDescriptionCraft::SkillActionDescriptionCraft()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTIONCRAFT;
}

bool SkillActionDescriptionCraft::operator==(const SkillActionDescriptionCraft &compared)
{
  if(probability == compared.probability)
  return true;
  
  return false;
}

