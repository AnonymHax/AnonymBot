#include "AchievementDetailedListMessage.h"

void AchievementDetailedListMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementDetailedListMessage(param1);
}

void AchievementDetailedListMessage::serializeAs_AchievementDetailedListMessage(Writer *param1)
{
  param1->writeShort((short)this->startedAchievements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->startedAchievements.size())
  {
    (this->startedAchievements[_loc2_]).serializeAs_Achievement(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->finishedAchievements.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->finishedAchievements.size())
  {
    (this->finishedAchievements[_loc3_]).serializeAs_Achievement(param1);
    _loc3_++;
  }
}

void AchievementDetailedListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementDetailedListMessage(param1);
}

void AchievementDetailedListMessage::deserializeAs_AchievementDetailedListMessage(Reader *param1)
{
  Achievement _loc6_ ;
  Achievement _loc7_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = Achievement();
    _loc6_.deserialize(param1);
    this->startedAchievements.append(_loc6_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = Achievement();
    _loc7_.deserialize(param1);
    this->finishedAchievements.append(_loc7_);
    _loc5_++;
  }
}

AchievementDetailedListMessage::AchievementDetailedListMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILEDLISTMESSAGE;
}

