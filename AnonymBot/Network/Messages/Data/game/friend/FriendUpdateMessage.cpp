#include "FriendUpdateMessage.h"

void FriendUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendUpdateMessage(param1);
}

void FriendUpdateMessage::serializeAs_FriendUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->friendUpdated->getTypes().last());
  this->friendUpdated->serialize(param1);
}

void FriendUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendUpdateMessage(param1);
}

void FriendUpdateMessage::deserializeAs_FriendUpdateMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->friendUpdated = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->friendUpdated->deserialize(param1);
}

FriendUpdateMessage::FriendUpdateMessage()
{
  m_type = MessageEnum::FRIENDUPDATEMESSAGE;
}

