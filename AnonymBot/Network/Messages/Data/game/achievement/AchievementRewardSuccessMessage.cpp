#include "AchievementRewardSuccessMessage.h"

void AchievementRewardSuccessMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementRewardSuccessMessage(param1);
}

void AchievementRewardSuccessMessage::serializeAs_AchievementRewardSuccessMessage(Writer *param1)
{
  param1->writeShort((short)this->achievementId);
}

void AchievementRewardSuccessMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementRewardSuccessMessage(param1);
}

void AchievementRewardSuccessMessage::deserializeAs_AchievementRewardSuccessMessage(Reader *param1)
{
  this->achievementId = param1->readShort();
}

AchievementRewardSuccessMessage::AchievementRewardSuccessMessage()
{
  m_type = MessageEnum::ACHIEVEMENTREWARDSUCCESSMESSAGE;
}

