#include "FriendWarnOnLevelGainStateMessage.h"

void FriendWarnOnLevelGainStateMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendWarnOnLevelGainStateMessage(param1);
}

void FriendWarnOnLevelGainStateMessage::serializeAs_FriendWarnOnLevelGainStateMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendWarnOnLevelGainStateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendWarnOnLevelGainStateMessage(param1);
}

void FriendWarnOnLevelGainStateMessage::deserializeAs_FriendWarnOnLevelGainStateMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendWarnOnLevelGainStateMessage::FriendWarnOnLevelGainStateMessage()
{
  m_type = MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE;
}

