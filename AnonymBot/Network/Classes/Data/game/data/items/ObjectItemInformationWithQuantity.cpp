#include "ObjectItemInformationWithQuantity.h"

void ObjectItemInformationWithQuantity::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemInformationWithQuantity(param1);
}

void ObjectItemInformationWithQuantity::serializeAs_ObjectItemInformationWithQuantity(Writer *param1)
{
  ObjectItemMinimalInformation::serializeAs_ObjectItemMinimalInformation(param1);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemInformationWithQuantity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  else
  {
    param1->writeVarInt((int)this->quantity);
    return;
  }
}

void ObjectItemInformationWithQuantity::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemInformationWithQuantity(param1);
}

void ObjectItemInformationWithQuantity::deserializeAs_ObjectItemInformationWithQuantity(Reader *param1)
{
  ObjectItemMinimalInformation::deserialize(param1);
  this->quantity = param1->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemInformationWithQuantity -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemInformationWithQuantity.quantity.";
  }
  else
  {
    return;
  }
}

ObjectItemInformationWithQuantity::ObjectItemInformationWithQuantity()
{
  m_types<<ClassEnum::OBJECTITEMINFORMATIONWITHQUANTITY;
}

bool ObjectItemInformationWithQuantity::operator==(const ObjectItemInformationWithQuantity &compared)
{
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

