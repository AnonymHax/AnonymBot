#include "ObjectItemToSell.h"

void ObjectItemToSell::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemToSell(param1);
}

void ObjectItemToSell::serializeAs_ObjectItemToSell(Writer *param1)
{
  Item::serializeAs_Item(param1);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
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
      qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
    }
    else
    {
      param1->writeVarInt((int)this->objectUID);
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
      }
      else
      {
        param1->writeVarInt((int)this->quantity);
        if(this->objectPrice < 0)
        {
          qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectPrice << ") on element objectPrice.";
        }
        else
        {
          param1->writeVarInt((int)this->objectPrice);
          return;
        }
      }
    }
  }
}

void ObjectItemToSell::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemToSell(param1);
}

void ObjectItemToSell::deserializeAs_ObjectItemToSell(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<ObjectEffect> _loc5_ ;
  Item::deserialize(param1);
  this->objectGID = param1->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemToSell.objectGID.";
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
      qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemToSell.objectUID.";
    }
    else
    {
      this->quantity = param1->readVarUhInt();
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemToSell.quantity.";
      }
      else
      {
        this->objectPrice = param1->readVarUhInt();
        if(this->objectPrice < 0)
        {
          qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectPrice << ") on element of ObjectItemToSell.objectPrice.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

ObjectItemToSell::ObjectItemToSell()
{
  m_types<<ClassEnum::OBJECTITEMTOSELL;
}

bool ObjectItemToSell::operator==(const ObjectItemToSell &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  if(objectPrice == compared.objectPrice)
  return true;
  
  return false;
}

