#include "FriendAddRequestMessage.h"

void FriendAddRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendAddRequestMessage(param1);
}

void FriendAddRequestMessage::serializeAs_FriendAddRequestMessage(Writer *param1)
{
  param1->writeUTF(this->name);
}

void FriendAddRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendAddRequestMessage(param1);
}

void FriendAddRequestMessage::deserializeAs_FriendAddRequestMessage(Reader *param1)
{
  this->name = param1->readUTF();
}

FriendAddRequestMessage::FriendAddRequestMessage()
{
  m_type = MessageEnum::FRIENDADDREQUESTMESSAGE;
}

