#include "ExchangeShopStockMultiMovementRemovedMessage.h"

void ExchangeShopStockMultiMovementRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeShopStockMultiMovementRemovedMessage(param1);
}

void ExchangeShopStockMultiMovementRemovedMessage::serializeAs_ExchangeShopStockMultiMovementRemovedMessage(Writer *param1)
{
  param1->writeShort((short)this->objectIdList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectIdList.size())
  {
    if(this->objectIdList[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeShopStockMultiMovementRemovedMessage -"<<"Forbidden value (" << this->objectIdList[_loc2_] << ") on element 1 (starting at 1) of objectIdList.";
    }
    else
    {
      param1->writeVarInt((int)this->objectIdList[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ExchangeShopStockMultiMovementRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeShopStockMultiMovementRemovedMessage(param1);
}

void ExchangeShopStockMultiMovementRemovedMessage::deserializeAs_ExchangeShopStockMultiMovementRemovedMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeShopStockMultiMovementRemovedMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of objectIdList.";
    }
    else
    {
      this->objectIdList.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ExchangeShopStockMultiMovementRemovedMessage::ExchangeShopStockMultiMovementRemovedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE;
}

