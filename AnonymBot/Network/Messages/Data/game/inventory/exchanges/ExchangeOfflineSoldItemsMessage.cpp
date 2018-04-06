#include "ExchangeOfflineSoldItemsMessage.h"

void ExchangeOfflineSoldItemsMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeOfflineSoldItemsMessage(param1);
}

void ExchangeOfflineSoldItemsMessage::serializeAs_ExchangeOfflineSoldItemsMessage(Writer *param1)
{
  param1->writeShort((short)this->bidHouseItems.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->bidHouseItems.size())
  {
    (this->bidHouseItems[_loc2_]).serializeAs_ObjectItemGenericQuantityPrice(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->merchantItems.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->merchantItems.size())
  {
    (this->merchantItems[_loc3_]).serializeAs_ObjectItemGenericQuantityPrice(param1);
    _loc3_++;
  }
}

void ExchangeOfflineSoldItemsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeOfflineSoldItemsMessage(param1);
}

void ExchangeOfflineSoldItemsMessage::deserializeAs_ExchangeOfflineSoldItemsMessage(Reader *param1)
{
  ObjectItemGenericQuantityPrice _loc6_ ;
  ObjectItemGenericQuantityPrice _loc7_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = ObjectItemGenericQuantityPrice();
    _loc6_.deserialize(param1);
    this->bidHouseItems.append(_loc6_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = ObjectItemGenericQuantityPrice();
    _loc7_.deserialize(param1);
    this->merchantItems.append(_loc7_);
    _loc5_++;
  }
}

ExchangeOfflineSoldItemsMessage::ExchangeOfflineSoldItemsMessage()
{
  m_type = MessageEnum::EXCHANGEOFFLINESOLDITEMSMESSAGE;
}

