#include "FriendWarnOnConnectionStateMessage.h"

void FriendWarnOnConnectionStateMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendWarnOnConnectionStateMessage(param1);
}

void FriendWarnOnConnectionStateMessage::serializeAs_FriendWarnOnConnectionStateMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendWarnOnConnectionStateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendWarnOnConnectionStateMessage(param1);
}

void FriendWarnOnConnectionStateMessage::deserializeAs_FriendWarnOnConnectionStateMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendWarnOnConnectionStateMessage::FriendWarnOnConnectionStateMessage()
{
  m_type = MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE;
}

