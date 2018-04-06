#include "ObjectItem.h"

void ObjectItem::serialize(Writer *param1)
{
  this->serializeAs_ObjectItem(param1);
}

void ObjectItem::serializeAs_ObjectItem(Writer *param1)
{
  Item::serializeAs_Item(param1);
  param1->writeByte(this->position);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
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
      qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
    }
    else
    {
      param1->writeVarInt((int)this->objectUID);
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
      }
      else
      {
        param1->writeVarInt((int)this->quantity);
        return;
      }
    }
  }
}

void ObjectItem::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItem(param1);
}

void ObjectItem::deserializeAs_ObjectItem(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<ObjectEffect> _loc5_ ;
  Item::deserialize(param1);
  this->position = param1->readUByte();
  if(this->position < 0 || this->position > 255)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->position << ") on element of ObjectItem.position.";
  }
  else
  {
    this->objectGID = param1->readVarUhShort();
    if(this->objectGID < 0)
    {
      qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItem.objectGID.";
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
        qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItem.objectUID.";
      }
      else
      {
        this->quantity = param1->readVarUhInt();
        if(this->quantity < 0)
        {
          qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItem.quantity.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

ObjectItem::ObjectItem()
{
  m_types<<ClassEnum::OBJECTITEM;
}

bool ObjectItem::operator==(const ObjectItem &compared)
{
  if(position == compared.position)
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

