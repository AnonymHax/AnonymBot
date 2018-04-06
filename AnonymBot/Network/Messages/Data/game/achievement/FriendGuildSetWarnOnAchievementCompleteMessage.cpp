#include "FriendGuildSetWarnOnAchievementCompleteMessage.h"

void FriendGuildSetWarnOnAchievementCompleteMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(param1);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::serializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(param1);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::deserializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendGuildSetWarnOnAchievementCompleteMessage::FriendGuildSetWarnOnAchievementCompleteMessage()
{
  m_type = MessageEnum::FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE;
}

