#include "ExchangeShopStockMultiMovementUpdatedMessage.h"

void ExchangeShopStockMultiMovementUpdatedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeShopStockMultiMovementUpdatedMessage(param1);
}

void ExchangeShopStockMultiMovementUpdatedMessage::serializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Writer *param1)
{
  param1->writeShort((short)this->objectInfoList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectInfoList.size())
  {
    qSharedPointerCast<ObjectItemToSell>(this->objectInfoList[_loc2_])->serializeAs_ObjectItemToSell(param1);
    _loc2_++;
  }
}

void ExchangeShopStockMultiMovementUpdatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeShopStockMultiMovementUpdatedMessage(param1);
}

void ExchangeShopStockMultiMovementUpdatedMessage::deserializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Reader *param1)
{
  QSharedPointer<ObjectItemToSell> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
    _loc4_->deserialize(param1);
    this->objectInfoList.append(_loc4_);
    _loc3_++;
  }
}

ExchangeShopStockMultiMovementUpdatedMessage::ExchangeShopStockMultiMovementUpdatedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE;
}

