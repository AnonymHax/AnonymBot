#include "KrosmasterInventoryMessage.h"

void KrosmasterInventoryMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterInventoryMessage(param1);
}

void KrosmasterInventoryMessage::serializeAs_KrosmasterInventoryMessage(Writer *param1)
{
  param1->writeShort((short)this->figures.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->figures.size())
  {
    (this->figures[_loc2_]).serializeAs_KrosmasterFigure(param1);
    _loc2_++;
  }
}

void KrosmasterInventoryMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterInventoryMessage(param1);
}

void KrosmasterInventoryMessage::deserializeAs_KrosmasterInventoryMessage(Reader *param1)
{
  KrosmasterFigure _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = KrosmasterFigure();
    _loc4_.deserialize(param1);
    this->figures.append(_loc4_);
    _loc3_++;
  }
}

KrosmasterInventoryMessage::KrosmasterInventoryMessage()
{
  m_type = MessageEnum::KROSMASTERINVENTORYMESSAGE;
}

