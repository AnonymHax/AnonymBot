#include "FriendDeleteResultMessage.h"

void FriendDeleteResultMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendDeleteResultMessage(param1);
}

void FriendDeleteResultMessage::serializeAs_FriendDeleteResultMessage(Writer *param1)
{
  param1->writeBool(this->success);
  param1->writeUTF(this->name);
}

void FriendDeleteResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendDeleteResultMessage(param1);
}

void FriendDeleteResultMessage::deserializeAs_FriendDeleteResultMessage(Reader *param1)
{
  this->success = param1->readBool();
  this->name = param1->readUTF();
}

FriendDeleteResultMessage::FriendDeleteResultMessage()
{
  m_type = MessageEnum::FRIENDDELETERESULTMESSAGE;
}

