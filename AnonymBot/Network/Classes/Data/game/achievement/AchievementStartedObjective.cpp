#include "AchievementStartedObjective.h"

void AchievementStartedObjective::serialize(Writer *param1)
{
  this->serializeAs_AchievementStartedObjective(param1);
}

void AchievementStartedObjective::serializeAs_AchievementStartedObjective(Writer *param1)
{
  AchievementObjective::serializeAs_AchievementObjective(param1);
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - AchievementStartedObjective -"<<"Forbidden value (" << this->value << ") on element value.";
  }
  else
  {
    param1->writeVarShort((int)this->value);
    return;
  }
}

void AchievementStartedObjective::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementStartedObjective(param1);
}

void AchievementStartedObjective::deserializeAs_AchievementStartedObjective(Reader *param1)
{
  AchievementObjective::deserialize(param1);
  this->value = param1->readVarUhShort();
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - AchievementStartedObjective -"<<"Forbidden value (" << this->value << ") on element of AchievementStartedObjective.value.";
  }
  else
  {
    return;
  }
}

AchievementStartedObjective::AchievementStartedObjective()
{
  m_types<<ClassEnum::ACHIEVEMENTSTARTEDOBJECTIVE;
}

bool AchievementStartedObjective::operator==(const AchievementStartedObjective &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

