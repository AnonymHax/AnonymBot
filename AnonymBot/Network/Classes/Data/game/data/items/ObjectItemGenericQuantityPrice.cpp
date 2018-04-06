#include "ObjectItemGenericQuantityPrice.h"

void ObjectItemGenericQuantityPrice::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemGenericQuantityPrice(param1);
}

void ObjectItemGenericQuantityPrice::serializeAs_ObjectItemGenericQuantityPrice(Writer *param1)
{
  ObjectItemGenericQuantity::serializeAs_ObjectItemGenericQuantity(param1);
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantityPrice -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  else
  {
    param1->writeVarInt((int)this->price);
    return;
  }
}

void ObjectItemGenericQuantityPrice::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemGenericQuantityPrice(param1);
}

void ObjectItemGenericQuantityPrice::deserializeAs_ObjectItemGenericQuantityPrice(Reader *param1)
{
  ObjectItemGenericQuantity::deserialize(param1);
  this->price = param1->readVarUhInt();
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantityPrice -"<<"Forbidden value (" << this->price << ") on element of ObjectItemGenericQuantityPrice.price.";
  }
  else
  {
    return;
  }
}

ObjectItemGenericQuantityPrice::ObjectItemGenericQuantityPrice()
{
  m_types<<ClassEnum::OBJECTITEMGENERICQUANTITYPRICE;
}

bool ObjectItemGenericQuantityPrice::operator==(const ObjectItemGenericQuantityPrice &compared)
{
  if(price == compared.price)
  return true;
  
  return false;
}

