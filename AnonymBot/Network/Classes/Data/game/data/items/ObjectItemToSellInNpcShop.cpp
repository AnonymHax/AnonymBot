#include "ObjectItemToSellInNpcShop.h"

void ObjectItemToSellInNpcShop::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemToSellInNpcShop(param1);
}

void ObjectItemToSellInNpcShop::serializeAs_ObjectItemToSellInNpcShop(Writer *param1)
{
  ObjectItemMinimalInformation::serializeAs_ObjectItemMinimalInformation(param1);
  if(this->objectPrice < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInNpcShop -"<<"Forbidden value (" << this->objectPrice << ") on element objectPrice.";
  }
  else
  {
    param1->writeVarInt((int)this->objectPrice);
    param1->writeUTF(this->buyCriterion);
    return;
  }
}

void ObjectItemToSellInNpcShop::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemToSellInNpcShop(param1);
}

void ObjectItemToSellInNpcShop::deserializeAs_ObjectItemToSellInNpcShop(Reader *param1)
{
  ObjectItemMinimalInformation::deserialize(param1);
  this->objectPrice = param1->readVarUhInt();
  if(this->objectPrice < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInNpcShop -"<<"Forbidden value (" << this->objectPrice << ") on element of ObjectItemToSellInNpcShop.objectPrice.";
  }
  else
  {
    this->buyCriterion = param1->readUTF();
    return;
  }
}

ObjectItemToSellInNpcShop::ObjectItemToSellInNpcShop()
{
  m_types<<ClassEnum::OBJECTITEMTOSELLINNPCSHOP;
}

bool ObjectItemToSellInNpcShop::operator==(const ObjectItemToSellInNpcShop &compared)
{
  if(objectPrice == compared.objectPrice)
  if(buyCriterion == compared.buyCriterion)
  return true;
  
  return false;
}

