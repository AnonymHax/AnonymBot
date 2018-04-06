#include "IndexedEntityLook.h"

void IndexedEntityLook::serialize(Writer *param1)
{
  this->serializeAs_IndexedEntityLook(param1);
}

void IndexedEntityLook::serializeAs_IndexedEntityLook(Writer *param1)
{
  this->look->serializeAs_EntityLook(param1);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - IndexedEntityLook -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  else
  {
    param1->writeByte(this->index);
    return;
  }
}

void IndexedEntityLook::deserialize(Reader *param1)
{
  this->deserializeAs_IndexedEntityLook(param1);
}

void IndexedEntityLook::deserializeAs_IndexedEntityLook(Reader *param1)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(param1);
  this->index = param1->readByte();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - IndexedEntityLook -"<<"Forbidden value (" << this->index << ") on element of IndexedEntityLook.index.";
  }
  else
  {
    return;
  }
}

IndexedEntityLook::IndexedEntityLook()
{
  m_types<<ClassEnum::INDEXEDENTITYLOOK;
}

bool IndexedEntityLook::operator==(const IndexedEntityLook &compared)
{
  if(look == compared.look)
  if(index == compared.index)
  return true;
  
  return false;
}

