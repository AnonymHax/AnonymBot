#include "FriendGuildWarnOnAchievementCompleteStateMessage.h"

void FriendGuildWarnOnAchievementCompleteStateMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(param1);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::serializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(param1);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::deserializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendGuildWarnOnAchievementCompleteStateMessage::FriendGuildWarnOnAchievementCompleteStateMessage()
{
  m_type = MessageEnum::FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE;
}

