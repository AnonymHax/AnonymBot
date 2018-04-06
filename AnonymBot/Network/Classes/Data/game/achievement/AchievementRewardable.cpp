#include "AchievementRewardable.h"

void AchievementRewardable::serialize(Writer *param1)
{
  this->serializeAs_AchievementRewardable(param1);
}

void AchievementRewardable::serializeAs_AchievementRewardable(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementRewardable -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    if(this->finishedlevel < 0 || this->finishedlevel > 206)
    {
      qDebug()<<"ERREUR - AchievementRewardable -"<<"Forbidden value (" << this->finishedlevel << ") on element finishedlevel.";
    }
    else
    {
      param1->writeByte(this->finishedlevel);
      return;
    }
  }
}

void AchievementRewardable::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementRewardable(param1);
}

void AchievementRewardable::deserializeAs_AchievementRewardable(Reader *param1)
{
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementRewardable -"<<"Forbidden value (" << this->id << ") on element of AchievementRewardable.id.";
  }
  else
  {
    this->finishedlevel = param1->readUByte();
    if(this->finishedlevel < 0 || this->finishedlevel > 206)
    {
      qDebug()<<"ERREUR - AchievementRewardable -"<<"Forbidden value (" << this->finishedlevel << ") on element of AchievementRewardable.finishedlevel.";
    }
    else
    {
      return;
    }
  }
}

AchievementRewardable::AchievementRewardable()
{
  m_types<<ClassEnum::ACHIEVEMENTREWARDABLE;
}

bool AchievementRewardable::operator==(const AchievementRewardable &compared)
{
  if(id == compared.id)
  if(finishedlevel == compared.finishedlevel)
  return true;
  
  return false;
}

