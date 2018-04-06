#include "ObjectItemGenericQuantity.h"

void ObjectItemGenericQuantity::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemGenericQuantity(param1);
}

void ObjectItemGenericQuantity::serializeAs_ObjectItemGenericQuantity(Writer *param1)
{
  Item::serializeAs_Item(param1);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  else
  {
    param1->writeVarShort((int)this->objectGID);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ObjectItemGenericQuantity::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemGenericQuantity(param1);
}

void ObjectItemGenericQuantity::deserializeAs_ObjectItemGenericQuantity(Reader *param1)
{
  Item::deserialize(param1);
  this->objectGID = param1->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemGenericQuantity.objectGID.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemGenericQuantity.quantity.";
    }
    else
    {
      return;
    }
  }
}

ObjectItemGenericQuantity::ObjectItemGenericQuantity()
{
  m_types<<ClassEnum::OBJECTITEMGENERICQUANTITY;
}

bool ObjectItemGenericQuantity::operator==(const ObjectItemGenericQuantity &compared)
{
  if(objectGID == compared.objectGID)
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

