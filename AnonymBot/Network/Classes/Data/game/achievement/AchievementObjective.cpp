#include "AchievementObjective.h"

void AchievementObjective::serialize(Writer *param1)
{
  this->serializeAs_AchievementObjective(param1);
}

void AchievementObjective::serializeAs_AchievementObjective(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarInt((int)this->id);
    if(this->maxValue < 0)
    {
      qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->maxValue << ") on element maxValue.";
    }
    else
    {
      param1->writeVarShort((int)this->maxValue);
      return;
    }
  }
}

void AchievementObjective::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementObjective(param1);
}

void AchievementObjective::deserializeAs_AchievementObjective(Reader *param1)
{
  this->id = param1->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->id << ") on element of AchievementObjective.id.";
  }
  else
  {
    this->maxValue = param1->readVarUhShort();
    if(this->maxValue < 0)
    {
      qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->maxValue << ") on element of AchievementObjective.maxValue.";
    }
    else
    {
      return;
    }
  }
}

AchievementObjective::AchievementObjective()
{
  m_types<<ClassEnum::ACHIEVEMENTOBJECTIVE;
}

bool AchievementObjective::operator==(const AchievementObjective &compared)
{
  if(id == compared.id)
  if(maxValue == compared.maxValue)
  return true;
  
  return false;
}

