#include "ExchangeStartedBidSellerMessage.h"

void ExchangeStartedBidSellerMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedBidSellerMessage(param1);
}

void ExchangeStartedBidSellerMessage::serializeAs_ExchangeStartedBidSellerMessage(Writer *param1)
{
  this->sellerDescriptor.serializeAs_SellerBuyerDescriptor(param1);
  param1->writeShort((short)this->objectsInfos.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectsInfos.size())
  {
    qSharedPointerCast<ObjectItemToSellInBid>(this->objectsInfos[_loc2_])->serializeAs_ObjectItemToSellInBid(param1);
    _loc2_++;
  }
}

void ExchangeStartedBidSellerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedBidSellerMessage(param1);
}

void ExchangeStartedBidSellerMessage::deserializeAs_ExchangeStartedBidSellerMessage(Reader *param1)
{
  QSharedPointer<ObjectItemToSellInBid> _loc4_ ;
  this->sellerDescriptor = SellerBuyerDescriptor();
  this->sellerDescriptor.deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItemToSellInBid>(new ObjectItemToSellInBid() );
    _loc4_->deserialize(param1);
    this->objectsInfos.append(_loc4_);
    _loc3_++;
  }
}

ExchangeStartedBidSellerMessage::ExchangeStartedBidSellerMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDBIDSELLERMESSAGE;
}

