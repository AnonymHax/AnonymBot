#include "FriendAddedMessage.h"

void FriendAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendAddedMessage(param1);
}

void FriendAddedMessage::serializeAs_FriendAddedMessage(Writer *param1)
{
  param1->writeShort((short)this->friendAdded->getTypes().last());
  this->friendAdded->serialize(param1);
}

void FriendAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendAddedMessage(param1);
}

void FriendAddedMessage::deserializeAs_FriendAddedMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->friendAdded = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->friendAdded->deserialize(param1);
}

FriendAddedMessage::FriendAddedMessage()
{
  m_type = MessageEnum::FRIENDADDEDMESSAGE;
}

