#include "ObjectItemInRolePlay.h"

void ObjectItemInRolePlay::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemInRolePlay(param1);
}

void ObjectItemInRolePlay::serializeAs_ObjectItemInRolePlay(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    if(this->objectGID < 0)
    {
      qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
    }
    else
    {
      param1->writeVarShort((int)this->objectGID);
      return;
    }
  }
}

void ObjectItemInRolePlay::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemInRolePlay(param1);
}

void ObjectItemInRolePlay::deserializeAs_ObjectItemInRolePlay(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->cellId << ") on element of ObjectItemInRolePlay.cellId.";
  }
  else
  {
    this->objectGID = param1->readVarUhShort();
    if(this->objectGID < 0)
    {
      qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemInRolePlay.objectGID.";
    }
    else
    {
      return;
    }
  }
}

ObjectItemInRolePlay::ObjectItemInRolePlay()
{
  m_types<<ClassEnum::OBJECTITEMINROLEPLAY;
}

bool ObjectItemInRolePlay::operator==(const ObjectItemInRolePlay &compared)
{
  if(cellId == compared.cellId)
  if(objectGID == compared.objectGID)
  return true;
  
  return false;
}

