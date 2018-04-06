#include "ExchangeBidPriceForSellerMessage.h"

void ExchangeBidPriceForSellerMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidPriceForSellerMessage(param1);
}

void ExchangeBidPriceForSellerMessage::serializeAs_ExchangeBidPriceForSellerMessage(Writer *param1)
{
  ExchangeBidPriceMessage::serializeAs_ExchangeBidPriceMessage(param1);
  param1->writeBool(this->allIdentical);
  param1->writeShort((short)this->minimalPrices.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->minimalPrices.size())
  {
    if(this->minimalPrices[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidPriceForSellerMessage -"<<"Forbidden value (" << this->minimalPrices[_loc2_] << ") on element 2 (starting at 1) of minimalPrices.";
    }
    else
    {
      param1->writeVarInt((int)this->minimalPrices[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ExchangeBidPriceForSellerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidPriceForSellerMessage(param1);
}

void ExchangeBidPriceForSellerMessage::deserializeAs_ExchangeBidPriceForSellerMessage(Reader *param1)
{
  uint _loc4_ = 0;
  ExchangeBidPriceMessage::deserialize(param1);
  this->allIdentical = param1->readBool();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidPriceForSellerMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of minimalPrices.";
    }
    else
    {
      this->minimalPrices.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ExchangeBidPriceForSellerMessage::ExchangeBidPriceForSellerMessage()
{
  m_type = MessageEnum::EXCHANGEBIDPRICEFORSELLERMESSAGE;
}

