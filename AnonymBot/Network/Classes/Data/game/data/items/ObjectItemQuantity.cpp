#include "ObjectItemQuantity.h"

void ObjectItemQuantity::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemQuantity(param1);
}

void ObjectItemQuantity::serializeAs_ObjectItemQuantity(Writer *param1)
{
  Item::serializeAs_Item(param1);
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ObjectItemQuantity::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemQuantity(param1);
}

void ObjectItemQuantity::deserializeAs_ObjectItemQuantity(Reader *param1)
{
  Item::deserialize(param1);
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemQuantity.objectUID.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemQuantity.quantity.";
    }
    else
    {
      return;
    }
  }
}

ObjectItemQuantity::ObjectItemQuantity()
{
  m_types<<ClassEnum::OBJECTITEMQUANTITY;
}

bool ObjectItemQuantity::operator==(const ObjectItemQuantity &compared)
{
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

