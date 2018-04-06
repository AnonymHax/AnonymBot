#include "AccountHouseMessage.h"

void AccountHouseMessage::serialize(Writer *param1)
{
  this->serializeAs_AccountHouseMessage(param1);
}

void AccountHouseMessage::serializeAs_AccountHouseMessage(Writer *param1)
{
  param1->writeShort((short)this->houses.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->houses.size())
  {
    (this->houses[_loc2_]).serializeAs_AccountHouseInformations(param1);
    _loc2_++;
  }
}

void AccountHouseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AccountHouseMessage(param1);
}

void AccountHouseMessage::deserializeAs_AccountHouseMessage(Reader *param1)
{
  AccountHouseInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = AccountHouseInformations();
    _loc4_.deserialize(param1);
    this->houses.append(_loc4_);
    _loc3_++;
  }
}

AccountHouseMessage::AccountHouseMessage()
{
  m_type = MessageEnum::ACCOUNTHOUSEMESSAGE;
}

