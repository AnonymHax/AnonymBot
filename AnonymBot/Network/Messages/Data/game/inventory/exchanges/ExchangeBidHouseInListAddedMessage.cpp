#include "ExchangeBidHouseInListAddedMessage.h"

void ExchangeBidHouseInListAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseInListAddedMessage(param1);
}

void ExchangeBidHouseInListAddedMessage::serializeAs_ExchangeBidHouseInListAddedMessage(Writer *param1)
{
  param1->writeInt((int)this->itemUID);
  param1->writeInt((int)this->objGenericId);
  param1->writeShort((short)this->effects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->effects.size())
  {
    param1->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_loc2_])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_loc2_])->serialize(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->prices.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->prices.size())
  {
    if(this->prices[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << this->prices[_loc3_] << ") on element 4 (starting at 1) of prices.";
    }
    else
    {
      param1->writeVarInt((int)this->prices[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void ExchangeBidHouseInListAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseInListAddedMessage(param1);
}

void ExchangeBidHouseInListAddedMessage::deserializeAs_ExchangeBidHouseInListAddedMessage(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<ObjectEffect> _loc7_ ;
  uint _loc8_ = 0;
  this->itemUID = param1->readInt();
  this->objGenericId = param1->readInt();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readUShort();
    _loc7_ = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_loc6_));
    _loc7_->deserialize(param1);
    this->effects.append(_loc7_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc8_ = param1->readVarUhInt();
    if(_loc8_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << _loc8_ << ") on elements of prices.";
    }
    else
    {
      this->prices.append(_loc8_);
      _loc5_++;
      continue;
    }
  }
}

ExchangeBidHouseInListAddedMessage::ExchangeBidHouseInListAddedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEINLISTADDEDMESSAGE;
}

