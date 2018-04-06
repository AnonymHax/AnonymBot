#include "DecraftResultMessage.h"

void DecraftResultMessage::serialize(Writer *param1)
{
  this->serializeAs_DecraftResultMessage(param1);
}

void DecraftResultMessage::serializeAs_DecraftResultMessage(Writer *param1)
{
  param1->writeShort((short)this->results.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->results.size())
  {
    (this->results[_loc2_]).serializeAs_DecraftedItemStackInfo(param1);
    _loc2_++;
  }
}

void DecraftResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DecraftResultMessage(param1);
}

void DecraftResultMessage::deserializeAs_DecraftResultMessage(Reader *param1)
{
  DecraftedItemStackInfo _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = DecraftedItemStackInfo();
    _loc4_.deserialize(param1);
    this->results.append(_loc4_);
    _loc3_++;
  }
}

DecraftResultMessage::DecraftResultMessage()
{
  m_type = MessageEnum::DECRAFTRESULTMESSAGE;
}

