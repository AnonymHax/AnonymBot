#include "SellerBuyerDescriptor.h"

void SellerBuyerDescriptor::serialize(Writer *param1)
{
  this->serializeAs_SellerBuyerDescriptor(param1);
}

void SellerBuyerDescriptor::serializeAs_SellerBuyerDescriptor(Writer *param1)
{
  param1->writeShort((short)this->quantities.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->quantities.size())
  {
    if(this->quantities[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->quantities[_loc2_] << ") on element 1 (starting at 1) of quantities.";
    }
    else
    {
      param1->writeVarInt((int)this->quantities[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->types.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->types.size())
  {
    if(this->types[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->types[_loc3_] << ") on element 2 (starting at 1) of types.";
    }
    else
    {
      param1->writeVarInt((int)this->types[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeFloat(this->taxPercentage);
  param1->writeFloat(this->taxModificationPercentage);
  if(this->maxItemLevel < 0 || this->maxItemLevel > 255)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemLevel << ") on element maxItemLevel.";
  }
  else
  {
    param1->writeByte(this->maxItemLevel);
    if(this->maxItemPerAccount < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemPerAccount << ") on element maxItemPerAccount.";
    }
    else
    {
      param1->writeVarInt((int)this->maxItemPerAccount);
      param1->writeInt((int)this->npcContextualId);
      if(this->unsoldDelay < 0)
      {
        qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->unsoldDelay << ") on element unsoldDelay.";
      }
      else
      {
        param1->writeVarShort((int)this->unsoldDelay);
        return;
      }
    }
  }
}

void SellerBuyerDescriptor::deserialize(Reader *param1)
{
  this->deserializeAs_SellerBuyerDescriptor(param1);
}

void SellerBuyerDescriptor::deserializeAs_SellerBuyerDescriptor(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhInt();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << _loc6_ << ") on elements of quantities.";
    }
    else
    {
      this->quantities.append(_loc6_);
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
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << _loc7_ << ") on elements of types.";
    }
    else
    {
      this->types.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
  this->taxPercentage = param1->readFloat();
  this->taxModificationPercentage = param1->readFloat();
  this->maxItemLevel = param1->readUByte();
  if(this->maxItemLevel < 0 || this->maxItemLevel > 255)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemLevel << ") on element of SellerBuyerDescriptor.maxItemLevel.";
  }
  else
  {
    this->maxItemPerAccount = param1->readVarUhInt();
    if(this->maxItemPerAccount < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemPerAccount << ") on element of SellerBuyerDescriptor.maxItemPerAccount.";
    }
    else
    {
      this->npcContextualId = param1->readInt();
      this->unsoldDelay = param1->readVarUhShort();
      if(this->unsoldDelay < 0)
      {
        qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->unsoldDelay << ") on element of SellerBuyerDescriptor.unsoldDelay.";
      }
      else
      {
        return;
      }
    }
  }
}

SellerBuyerDescriptor::SellerBuyerDescriptor()
{
  m_types<<ClassEnum::SELLERBUYERDESCRIPTOR;
}

bool SellerBuyerDescriptor::operator==(const SellerBuyerDescriptor &compared)
{
  if(quantities == compared.quantities)
  if(types == compared.types)
  if(taxPercentage == compared.taxPercentage)
  if(taxModificationPercentage == compared.taxModificationPercentage)
  if(maxItemLevel == compared.maxItemLevel)
  if(maxItemPerAccount == compared.maxItemPerAccount)
  if(npcContextualId == compared.npcContextualId)
  if(unsoldDelay == compared.unsoldDelay)
  return true;
  
  return false;
}

