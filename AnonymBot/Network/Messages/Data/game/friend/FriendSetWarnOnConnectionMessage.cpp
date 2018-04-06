#include "FriendSetWarnOnConnectionMessage.h"

void FriendSetWarnOnConnectionMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendSetWarnOnConnectionMessage(param1);
}

void FriendSetWarnOnConnectionMessage::serializeAs_FriendSetWarnOnConnectionMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendSetWarnOnConnectionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendSetWarnOnConnectionMessage(param1);
}

void FriendSetWarnOnConnectionMessage::deserializeAs_FriendSetWarnOnConnectionMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendSetWarnOnConnectionMessage::FriendSetWarnOnConnectionMessage()
{
  m_type = MessageEnum::FRIENDSETWARNONCONNECTIONMESSAGE;
}

