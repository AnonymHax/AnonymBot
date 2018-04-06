#include "ExchangeStartOkHumanVendorMessage.h"

void ExchangeStartOkHumanVendorMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkHumanVendorMessage(param1);
}

void ExchangeStartOkHumanVendorMessage::serializeAs_ExchangeStartOkHumanVendorMessage(Writer *param1)
{
  if(this->sellerId < -9.007199254740992E15 || this->sellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkHumanVendorMessage -"<<"Forbidden value (" << this->sellerId << ") on element sellerId.";
  }
  else
  {
    param1->writeDouble(this->sellerId);
    param1->writeShort((short)this->objectsInfos.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->objectsInfos.size())
    {
      qSharedPointerCast<ObjectItemToSellInHumanVendorShop>(this->objectsInfos[_loc2_])->serializeAs_ObjectItemToSellInHumanVendorShop(param1);
      _loc2_++;
    }
    return;
  }
}

void ExchangeStartOkHumanVendorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkHumanVendorMessage(param1);
}

void ExchangeStartOkHumanVendorMessage::deserializeAs_ExchangeStartOkHumanVendorMessage(Reader *param1)
{
  QSharedPointer<ObjectItemToSellInHumanVendorShop> _loc4_ ;
  this->sellerId = param1->readDouble();
  if(this->sellerId < -9.007199254740992E15 || this->sellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkHumanVendorMessage -"<<"Forbidden value (" << this->sellerId << ") on element of ExchangeStartOkHumanVendorMessage.sellerId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = QSharedPointer<ObjectItemToSellInHumanVendorShop>(new ObjectItemToSellInHumanVendorShop() );
      _loc4_->deserialize(param1);
      this->objectsInfos.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

ExchangeStartOkHumanVendorMessage::ExchangeStartOkHumanVendorMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKHUMANVENDORMESSAGE;
}

