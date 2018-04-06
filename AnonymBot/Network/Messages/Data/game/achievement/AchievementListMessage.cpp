#include "AchievementListMessage.h"

void AchievementListMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementListMessage(param1);
}

void AchievementListMessage::serializeAs_AchievementListMessage(Writer *param1)
{
  param1->writeShort((short)this->finishedAchievementsIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->finishedAchievementsIds.size())
  {
    if(this->finishedAchievementsIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - AchievementListMessage -"<<"Forbidden value (" << this->finishedAchievementsIds[_loc2_] << ") on element 1 (starting at 1) of finishedAchievementsIds.";
    }
    else
    {
      param1->writeVarShort((int)this->finishedAchievementsIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->rewardableAchievements.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->rewardableAchievements.size())
  {
    (this->rewardableAchievements[_loc3_]).serializeAs_AchievementRewardable(param1);
    _loc3_++;
  }
}

void AchievementListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementListMessage(param1);
}

void AchievementListMessage::deserializeAs_AchievementListMessage(Reader *param1)
{
  uint _loc6_ = 0;
  AchievementRewardable _loc7_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - AchievementListMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of finishedAchievementsIds.";
    }
    else
    {
      this->finishedAchievementsIds.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = AchievementRewardable();
    _loc7_.deserialize(param1);
    this->rewardableAchievements.append(_loc7_);
    _loc5_++;
  }
}

AchievementListMessage::AchievementListMessage()
{
  m_type = MessageEnum::ACHIEVEMENTLISTMESSAGE;
}

