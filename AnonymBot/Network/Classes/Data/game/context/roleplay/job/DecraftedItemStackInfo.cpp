#include "DecraftedItemStackInfo.h"

void DecraftedItemStackInfo::serialize(Writer *param1)
{
  this->serializeAs_DecraftedItemStackInfo(param1);
}

void DecraftedItemStackInfo::serializeAs_DecraftedItemStackInfo(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    param1->writeFloat(this->bonusMin);
    param1->writeFloat(this->bonusMax);
    param1->writeShort((short)this->runesId.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->runesId.size())
    {
      if(this->runesId[_loc2_] < 0)
      {
        qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->runesId[_loc2_] << ") on element 4 (starting at 1) of runesId.";
      }
      else
      {
        param1->writeVarShort((int)this->runesId[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    param1->writeShort((short)this->runesQty.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->runesQty.size())
    {
      if(this->runesQty[_loc3_] < 0)
      {
        qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->runesQty[_loc3_] << ") on element 5 (starting at 1) of runesQty.";
      }
      else
      {
        param1->writeVarInt((int)this->runesQty[_loc3_]);
        _loc3_++;
        continue;
      }
    }
    return;
  }
}

void DecraftedItemStackInfo::deserialize(Reader *param1)
{
  this->deserializeAs_DecraftedItemStackInfo(param1);
}

void DecraftedItemStackInfo::deserializeAs_DecraftedItemStackInfo(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->objectUID << ") on element of DecraftedItemStackInfo.objectUID.";
  }
  else
  {
    this->bonusMin = param1->readFloat();
    this->bonusMax = param1->readFloat();
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readVarUhShort();
      if(_loc6_ < 0)
      {
        qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << _loc6_ << ") on elements of runesId.";
      }
      else
      {
        this->runesId.append(_loc6_);
        _loc3_++;
        continue;
      }
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc7_ = param1->readVarUhInt();
      if(_loc7_ < 0)
      {
        qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << _loc7_ << ") on elements of runesQty.";
      }
      else
      {
        this->runesQty.append(_loc7_);
        _loc5_++;
        continue;
      }
    }
    return;
  }
}

DecraftedItemStackInfo::DecraftedItemStackInfo()
{
  m_types<<ClassEnum::DECRAFTEDITEMSTACKINFO;
}

bool DecraftedItemStackInfo::operator==(const DecraftedItemStackInfo &compared)
{
  if(objectUID == compared.objectUID)
  if(bonusMin == compared.bonusMin)
  if(bonusMax == compared.bonusMax)
  if(runesId == compared.runesId)
  if(runesQty == compared.runesQty)
  return true;
  
  return false;
}

