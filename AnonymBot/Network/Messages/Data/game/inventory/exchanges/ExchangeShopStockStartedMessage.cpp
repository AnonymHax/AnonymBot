#include "ExchangeShopStockStartedMessage.h"

void ExchangeShopStockStartedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeShopStockStartedMessage(param1);
}

void ExchangeShopStockStartedMessage::serializeAs_ExchangeShopStockStartedMessage(Writer *param1)
{
  param1->writeShort((short)this->objectsInfos.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectsInfos.size())
  {
    qSharedPointerCast<ObjectItemToSell>(this->objectsInfos[_loc2_])->serializeAs_ObjectItemToSell(param1);
    _loc2_++;
  }
}

void ExchangeShopStockStartedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeShopStockStartedMessage(param1);
}

void ExchangeShopStockStartedMessage::deserializeAs_ExchangeShopStockStartedMessage(Reader *param1)
{
  QSharedPointer<ObjectItemToSell> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
    _loc4_->deserialize(param1);
    this->objectsInfos.append(_loc4_);
    _loc3_++;
  }
}

ExchangeShopStockStartedMessage::ExchangeShopStockStartedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKSTARTEDMESSAGE;
}

