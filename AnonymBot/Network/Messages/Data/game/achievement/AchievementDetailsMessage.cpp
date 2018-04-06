#include "AchievementDetailsMessage.h"

void AchievementDetailsMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementDetailsMessage(param1);
}

void AchievementDetailsMessage::serializeAs_AchievementDetailsMessage(Writer *param1)
{
  this->achievement.serializeAs_Achievement(param1);
}

void AchievementDetailsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementDetailsMessage(param1);
}

void AchievementDetailsMessage::deserializeAs_AchievementDetailsMessage(Reader *param1)
{
  this->achievement = Achievement();
  this->achievement.deserialize(param1);
}

AchievementDetailsMessage::AchievementDetailsMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILSMESSAGE;
}

