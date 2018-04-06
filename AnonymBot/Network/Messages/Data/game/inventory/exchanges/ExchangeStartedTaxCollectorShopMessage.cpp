#include "ExchangeStartedTaxCollectorShopMessage.h"

void ExchangeStartedTaxCollectorShopMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedTaxCollectorShopMessage(param1);
}

void ExchangeStartedTaxCollectorShopMessage::serializeAs_ExchangeStartedTaxCollectorShopMessage(Writer *param1)
{
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    qSharedPointerCast<ObjectItem>(this->objects[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedTaxCollectorShopMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  else
  {
    param1->writeVarInt((int)this->kamas);
    return;
  }
}

void ExchangeStartedTaxCollectorShopMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedTaxCollectorShopMessage(param1);
}

void ExchangeStartedTaxCollectorShopMessage::deserializeAs_ExchangeStartedTaxCollectorShopMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->objects.append(_loc4_);
    _loc3_++;
  }
  this->kamas = param1->readVarUhInt();
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedTaxCollectorShopMessage -"<<"Forbidden value (" << this->kamas << ") on element of ExchangeStartedTaxCollectorShopMessage.kamas.";
  }
  else
  {
    return;
  }
}

ExchangeStartedTaxCollectorShopMessage::ExchangeStartedTaxCollectorShopMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE;
}

