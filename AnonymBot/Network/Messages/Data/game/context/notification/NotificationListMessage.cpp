#include "NotificationListMessage.h"

void NotificationListMessage::serialize(Writer *param1)
{
  this->serializeAs_NotificationListMessage(param1);
}

void NotificationListMessage::serializeAs_NotificationListMessage(Writer *param1)
{
  param1->writeShort((short)this->flags.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->flags.size())
  {
    param1->writeVarInt((int)this->flags[_loc2_]);
    _loc2_++;
  }
}

void NotificationListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NotificationListMessage(param1);
}

void NotificationListMessage::deserializeAs_NotificationListMessage(Reader *param1)
{
  auto _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarInt();
    this->flags.append(_loc4_);
    _loc3_++;
  }
}

NotificationListMessage::NotificationListMessage()
{
  m_type = MessageEnum::NOTIFICATIONLISTMESSAGE;
}

