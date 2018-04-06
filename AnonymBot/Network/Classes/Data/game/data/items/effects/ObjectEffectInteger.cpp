#include "ObjectEffectInteger.h"

void ObjectEffectInteger::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectInteger(param1);
}

void ObjectEffectInteger::serializeAs_ObjectEffectInteger(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectInteger -"<<"Forbidden value (" << this->value << ") on element value.";
  }
  else
  {
    param1->writeVarShort((int)this->value);
    return;
  }
}

void ObjectEffectInteger::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectInteger(param1);
}

void ObjectEffectInteger::deserializeAs_ObjectEffectInteger(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->value = param1->readVarUhShort();
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectInteger -"<<"Forbidden value (" << this->value << ") on element of ObjectEffectInteger.value.";
  }
  else
  {
    return;
  }
}

ObjectEffectInteger::ObjectEffectInteger()
{
  m_types<<ClassEnum::OBJECTEFFECTINTEGER;
}

bool ObjectEffectInteger::operator==(const ObjectEffectInteger &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

