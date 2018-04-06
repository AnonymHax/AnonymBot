#include "ExchangeStartedMountStockMessage.h"

void ExchangeStartedMountStockMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedMountStockMessage(param1);
}

void ExchangeStartedMountStockMessage::serializeAs_ExchangeStartedMountStockMessage(Writer *param1)
{
  param1->writeShort((short)this->objectsInfos.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectsInfos.size())
  {
    qSharedPointerCast<ObjectItem>(this->objectsInfos[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void ExchangeStartedMountStockMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedMountStockMessage(param1);
}

void ExchangeStartedMountStockMessage::deserializeAs_ExchangeStartedMountStockMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->objectsInfos.append(_loc4_);
    _loc3_++;
  }
}

ExchangeStartedMountStockMessage::ExchangeStartedMountStockMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDMOUNTSTOCKMESSAGE;
}

