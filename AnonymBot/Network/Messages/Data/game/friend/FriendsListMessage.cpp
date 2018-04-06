#include "FriendsListMessage.h"

void FriendsListMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendsListMessage(param1);
}

void FriendsListMessage::serializeAs_FriendsListMessage(Writer *param1)
{
  param1->writeShort((short)this->friendsList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->friendsList.size())
  {
    param1->writeShort((short)qSharedPointerCast<FriendInformations>(this->friendsList[_loc2_])->getTypes().last());
    qSharedPointerCast<FriendInformations>(this->friendsList[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void FriendsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendsListMessage(param1);
}

void FriendsListMessage::deserializeAs_FriendsListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<FriendInformations> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->friendsList.append(_loc5_);
    _loc3_++;
  }
}

FriendsListMessage::FriendsListMessage()
{
  m_type = MessageEnum::FRIENDSLISTMESSAGE;
}

