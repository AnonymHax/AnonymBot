#include "ObjectEffect.h"

void ObjectEffect::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffect(param1);
}

void ObjectEffect::serializeAs_ObjectEffect(Writer *param1)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffect -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  else
  {
    param1->writeVarShort((int)this->actionId);
    return;
  }
}

void ObjectEffect::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffect(param1);
}

void ObjectEffect::deserializeAs_ObjectEffect(Reader *param1)
{
  this->actionId = param1->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffect -"<<"Forbidden value (" << this->actionId << ") on element of ObjectEffect.actionId.";
  }
  else
  {
    return;
  }
}

ObjectEffect::ObjectEffect()
{
  m_types<<ClassEnum::OBJECTEFFECT;
}

bool ObjectEffect::operator==(const ObjectEffect &compared)
{
  if(actionId == compared.actionId)
  return true;
  
  return false;
}

