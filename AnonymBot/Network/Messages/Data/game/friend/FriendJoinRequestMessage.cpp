#include "FriendJoinRequestMessage.h"

void FriendJoinRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendJoinRequestMessage(param1);
}

void FriendJoinRequestMessage::serializeAs_FriendJoinRequestMessage(Writer *param1)
{
  param1->writeUTF(this->name);
}

void FriendJoinRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendJoinRequestMessage(param1);
}

void FriendJoinRequestMessage::deserializeAs_FriendJoinRequestMessage(Reader *param1)
{
  this->name = param1->readUTF();
}

FriendJoinRequestMessage::FriendJoinRequestMessage()
{
  m_type = MessageEnum::FRIENDJOINREQUESTMESSAGE;
}

