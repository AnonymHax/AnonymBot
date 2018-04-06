#include "ObjectItemToSellInHumanVendorShop.h"

void ObjectItemToSellInHumanVendorShop::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemToSellInHumanVendorShop(param1);
}

void ObjectItemToSellInHumanVendorShop::serializeAs_ObjectItemToSellInHumanVendorShop(Writer *param1)
{
  Item::serializeAs_Item(param1);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  else
  {
    param1->writeVarShort((int)this->objectGID);
    param1->writeShort((short)this->effects.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->effects.size())
    {
      param1->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_loc2_])->getTypes().last());
      qSharedPointerCast<ObjectEffect>(this->effects[_loc2_])->serialize(param1);
      _loc2_++;
    }
    if(this->objectUID < 0)
    {
      qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
    }
    else
    {
      param1->writeVarInt((int)this->objectUID);
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
      }
      else
      {
        param1->writeVarInt((int)this->quantity);
        if(this->objectPrice < 0)
        {
          qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectPrice << ") on element objectPrice.";
        }
        else
        {
          param1->writeVarInt((int)this->objectPrice);
          if(this->publicPrice < 0)
          {
            qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->publicPrice << ") on element publicPrice.";
          }
          else
          {
            param1->writeVarInt((int)this->publicPrice);
            return;
          }
        }
      }
    }
  }
}

void ObjectItemToSellInHumanVendorShop::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemToSellInHumanVendorShop(param1);
}

void ObjectItemToSellInHumanVendorShop::deserializeAs_ObjectItemToSellInHumanVendorShop(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<ObjectEffect> _loc5_ ;
  Item::deserialize(param1);
  this->objectGID = param1->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemToSellInHumanVendorShop.objectGID.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->effects.append(_loc5_);
      _loc3_++;
    }
    this->objectUID = param1->readVarUhInt();
    if(this->objectUID < 0)
    {
      qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemToSellInHumanVendorShop.objectUID.";
    }
    else
    {
      this->quantity = param1->readVarUhInt();
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemToSellInHumanVendorShop.quantity.";
      }
      else
      {
        this->objectPrice = param1->readVarUhInt();
        if(this->objectPrice < 0)
        {
          qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectPrice << ") on element of ObjectItemToSellInHumanVendorShop.objectPrice.";
        }
        else
        {
          this->publicPrice = param1->readVarUhInt();
          if(this->publicPrice < 0)
          {
            qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->publicPrice << ") on element of ObjectItemToSellInHumanVendorShop.publicPrice.";
          }
          else
          {
            return;
          }
        }
      }
    }
  }
}

ObjectItemToSellInHumanVendorShop::ObjectItemToSellInHumanVendorShop()
{
  m_types<<ClassEnum::OBJECTITEMTOSELLINHUMANVENDORSHOP;
}

bool ObjectItemToSellInHumanVendorShop::operator==(const ObjectItemToSellInHumanVendorShop &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  if(objectPrice == compared.objectPrice)
  if(publicPrice == compared.publicPrice)
  return true;
  
  return false;
}

