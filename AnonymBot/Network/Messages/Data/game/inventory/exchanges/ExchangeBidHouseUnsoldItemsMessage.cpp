#include "ExchangeBidHouseUnsoldItemsMessage.h"

void ExchangeBidHouseUnsoldItemsMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseUnsoldItemsMessage(param1);
}

void ExchangeBidHouseUnsoldItemsMessage::serializeAs_ExchangeBidHouseUnsoldItemsMessage(Writer *param1)
{
  param1->writeShort((short)this->items.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->items.size())
  {
    (this->items[_loc2_]).serializeAs_ObjectItemGenericQuantity(param1);
    _loc2_++;
  }
}

void ExchangeBidHouseUnsoldItemsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseUnsoldItemsMessage(param1);
}

void ExchangeBidHouseUnsoldItemsMessage::deserializeAs_ExchangeBidHouseUnsoldItemsMessage(Reader *param1)
{
  ObjectItemGenericQuantity _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = ObjectItemGenericQuantity();
    _loc4_.deserialize(param1);
    this->items.append(_loc4_);
    _loc3_++;
  }
}

ExchangeBidHouseUnsoldItemsMessage::ExchangeBidHouseUnsoldItemsMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE;
}

