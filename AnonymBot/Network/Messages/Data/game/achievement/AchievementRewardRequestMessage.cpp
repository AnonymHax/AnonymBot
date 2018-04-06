#include "AchievementRewardRequestMessage.h"

void AchievementRewardRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementRewardRequestMessage(param1);
}

void AchievementRewardRequestMessage::serializeAs_AchievementRewardRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->achievementId);
}

void AchievementRewardRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementRewardRequestMessage(param1);
}

void AchievementRewardRequestMessage::deserializeAs_AchievementRewardRequestMessage(Reader *param1)
{
  this->achievementId = param1->readShort();
}

AchievementRewardRequestMessage::AchievementRewardRequestMessage()
{
  m_type = MessageEnum::ACHIEVEMENTREWARDREQUESTMESSAGE;
}

