#include "BidExchangerObjectInfo.h"

void BidExchangerObjectInfo::serialize(Writer *param1)
{
  this->serializeAs_BidExchangerObjectInfo(param1);
}

void BidExchangerObjectInfo::serializeAs_BidExchangerObjectInfo(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
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
        qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->prices[_loc3_] << ") on element 3 (starting at 1) of prices.";
      }
      else
      {
        param1->writeInt((int)this->prices[_loc3_]);
        _loc3_++;
        continue;
      }
    }
    return;
  }
}

void BidExchangerObjectInfo::deserialize(Reader *param1)
{
  this->deserializeAs_BidExchangerObjectInfo(param1);
}

void BidExchangerObjectInfo::deserializeAs_BidExchangerObjectInfo(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<ObjectEffect> _loc7_ ;
  uint _loc8_ = 0;
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectUID << ") on element of BidExchangerObjectInfo.objectUID.";
  }
  else
  {
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
      _loc8_ = param1->readInt();
      if(_loc8_ < 0)
      {
        qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << _loc8_ << ") on elements of prices.";
      }
      else
      {
        this->prices.append(_loc8_);
        _loc5_++;
        continue;
      }
    }
    return;
  }
}

BidExchangerObjectInfo::BidExchangerObjectInfo()
{
  m_types<<ClassEnum::BIDEXCHANGEROBJECTINFO;
}

bool BidExchangerObjectInfo::operator==(const BidExchangerObjectInfo &compared)
{
  if(objectUID == compared.objectUID)
  if(effects == compared.effects)
  if(prices == compared.prices)
  return true;
  
  return false;
}

