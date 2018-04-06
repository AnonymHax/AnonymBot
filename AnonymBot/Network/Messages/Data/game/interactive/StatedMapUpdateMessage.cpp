#include "StatedMapUpdateMessage.h"

void StatedMapUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_StatedMapUpdateMessage(param1);
}

void StatedMapUpdateMessage::serializeAs_StatedMapUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->statedElements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->statedElements.size())
  {
    (this->statedElements[_loc2_]).serializeAs_StatedElement(param1);
    _loc2_++;
  }
}

void StatedMapUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StatedMapUpdateMessage(param1);
}

void StatedMapUpdateMessage::deserializeAs_StatedMapUpdateMessage(Reader *param1)
{
  StatedElement _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = StatedElement();
    _loc4_.deserialize(param1);
    this->statedElements.append(_loc4_);
    _loc3_++;
  }
}

StatedMapUpdateMessage::StatedMapUpdateMessage()
{
  m_type = MessageEnum::STATEDMAPUPDATEMESSAGE;
}

