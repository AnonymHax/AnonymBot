#include "ObjectItemToSellInBid.h"

void ObjectItemToSellInBid::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemToSellInBid(param1);
}

void ObjectItemToSellInBid::serializeAs_ObjectItemToSellInBid(Writer *param1)
{
  ObjectItemToSell::serializeAs_ObjectItemToSell(param1);
  if(this->unsoldDelay < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInBid -"<<"Forbidden value (" << this->unsoldDelay << ") on element unsoldDelay.";
  }
  else
  {
    param1->writeInt((int)this->unsoldDelay);
    return;
  }
}

void ObjectItemToSellInBid::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemToSellInBid(param1);
}

void ObjectItemToSellInBid::deserializeAs_ObjectItemToSellInBid(Reader *param1)
{
  ObjectItemToSell::deserialize(param1);
  this->unsoldDelay = param1->readInt();
  if(this->unsoldDelay < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInBid -"<<"Forbidden value (" << this->unsoldDelay << ") on element of ObjectItemToSellInBid.unsoldDelay.";
  }
  else
  {
    return;
  }
}

ObjectItemToSellInBid::ObjectItemToSellInBid()
{
  m_types<<ClassEnum::OBJECTITEMTOSELLINBID;
}

bool ObjectItemToSellInBid::operator==(const ObjectItemToSellInBid &compared)
{
  if(unsoldDelay == compared.unsoldDelay)
  return true;
  
  return false;
}

