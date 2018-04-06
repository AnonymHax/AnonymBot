#include "ObjectEffectCreature.h"

void ObjectEffectCreature::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectCreature(param1);
}

void ObjectEffectCreature::serializeAs_ObjectEffectCreature(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->monsterFamilyId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectCreature -"<<"Forbidden value (" << this->monsterFamilyId << ") on element monsterFamilyId.";
  }
  else
  {
    param1->writeVarShort((int)this->monsterFamilyId);
    return;
  }
}

void ObjectEffectCreature::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectCreature(param1);
}

void ObjectEffectCreature::deserializeAs_ObjectEffectCreature(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->monsterFamilyId = param1->readVarUhShort();
  if(this->monsterFamilyId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectCreature -"<<"Forbidden value (" << this->monsterFamilyId << ") on element of ObjectEffectCreature.monsterFamilyId.";
  }
  else
  {
    return;
  }
}

ObjectEffectCreature::ObjectEffectCreature()
{
  m_types<<ClassEnum::OBJECTEFFECTCREATURE;
}

bool ObjectEffectCreature::operator==(const ObjectEffectCreature &compared)
{
  if(monsterFamilyId == compared.monsterFamilyId)
  return true;
  
  return false;
}

