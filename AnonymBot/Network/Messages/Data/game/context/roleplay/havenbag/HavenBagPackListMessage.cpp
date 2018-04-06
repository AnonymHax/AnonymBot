#include "HavenBagPackListMessage.h"

void HavenBagPackListMessage::serialize(Writer *param1)
{
  this->serializeAs_HavenBagPackListMessage(param1);
}

void HavenBagPackListMessage::serializeAs_HavenBagPackListMessage(Writer *param1)
{
  param1->writeShort((short)this->packIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->packIds.size())
  {
    param1->writeByte(this->packIds[_loc2_]);
    _loc2_++;
  }
}

void HavenBagPackListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HavenBagPackListMessage(param1);
}

void HavenBagPackListMessage::deserializeAs_HavenBagPackListMessage(Reader *param1)
{
  auto _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    this->packIds.append(_loc4_);
    _loc3_++;
  }
}

HavenBagPackListMessage::HavenBagPackListMessage()
{
  m_type = MessageEnum::HAVENBAGPACKLISTMESSAGE;
}

