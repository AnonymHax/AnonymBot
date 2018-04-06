#include "AchievementRewardErrorMessage.h"

void AchievementRewardErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementRewardErrorMessage(param1);
}

void AchievementRewardErrorMessage::serializeAs_AchievementRewardErrorMessage(Writer *param1)
{
  param1->writeShort((short)this->achievementId);
}

void AchievementRewardErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementRewardErrorMessage(param1);
}

void AchievementRewardErrorMessage::deserializeAs_AchievementRewardErrorMessage(Reader *param1)
{
  this->achievementId = param1->readShort();
}

AchievementRewardErrorMessage::AchievementRewardErrorMessage()
{
  m_type = MessageEnum::ACHIEVEMENTREWARDERRORMESSAGE;
}

