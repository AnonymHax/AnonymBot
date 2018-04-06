#include "ObjectEffectString.h"

void ObjectEffectString::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectString(param1);
}

void ObjectEffectString::serializeAs_ObjectEffectString(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  param1->writeUTF(this->value);
}

void ObjectEffectString::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectString(param1);
}

void ObjectEffectString::deserializeAs_ObjectEffectString(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->value = param1->readUTF();
}

ObjectEffectString::ObjectEffectString()
{
  m_types<<ClassEnum::OBJECTEFFECTSTRING;
}

bool ObjectEffectString::operator==(const ObjectEffectString &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

