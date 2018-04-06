#include "ExchangeMountsPaddockRemoveMessage.h"

void ExchangeMountsPaddockRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMountsPaddockRemoveMessage(param1);
}

void ExchangeMountsPaddockRemoveMessage::serializeAs_ExchangeMountsPaddockRemoveMessage(Writer *param1)
{
  param1->writeShort((short)this->mountsId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->mountsId.size())
  {
    param1->writeVarInt((int)this->mountsId[_loc2_]);
    _loc2_++;
  }
}

void ExchangeMountsPaddockRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMountsPaddockRemoveMessage(param1);
}

void ExchangeMountsPaddockRemoveMessage::deserializeAs_ExchangeMountsPaddockRemoveMessage(Reader *param1)
{
  auto _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarInt();
    this->mountsId.append(_loc4_);
    _loc3_++;
  }
}

ExchangeMountsPaddockRemoveMessage::ExchangeMountsPaddockRemoveMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE;
}

