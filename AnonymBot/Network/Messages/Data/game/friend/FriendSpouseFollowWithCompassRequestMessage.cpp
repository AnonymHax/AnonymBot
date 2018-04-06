#include "FriendSpouseFollowWithCompassRequestMessage.h"

void FriendSpouseFollowWithCompassRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendSpouseFollowWithCompassRequestMessage(param1);
}

void FriendSpouseFollowWithCompassRequestMessage::serializeAs_FriendSpouseFollowWithCompassRequestMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendSpouseFollowWithCompassRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendSpouseFollowWithCompassRequestMessage(param1);
}

void FriendSpouseFollowWithCompassRequestMessage::deserializeAs_FriendSpouseFollowWithCompassRequestMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendSpouseFollowWithCompassRequestMessage::FriendSpouseFollowWithCompassRequestMessage()
{
  m_type = MessageEnum::FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE;
}

