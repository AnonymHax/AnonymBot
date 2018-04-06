#include "ObjectEffectLadder.h"

void ObjectEffectLadder::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectLadder(param1);
}

void ObjectEffectLadder::serializeAs_ObjectEffectLadder(Writer *param1)
{
  ObjectEffectCreature::serializeAs_ObjectEffectCreature(param1);
  if(this->monsterCount < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectLadder -"<<"Forbidden value (" << this->monsterCount << ") on element monsterCount.";
  }
  else
  {
    param1->writeVarInt((int)this->monsterCount);
    return;
  }
}

void ObjectEffectLadder::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectLadder(param1);
}

void ObjectEffectLadder::deserializeAs_ObjectEffectLadder(Reader *param1)
{
  ObjectEffectCreature::deserialize(param1);
  this->monsterCount = param1->readVarUhInt();
  if(this->monsterCount < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectLadder -"<<"Forbidden value (" << this->monsterCount << ") on element of ObjectEffectLadder.monsterCount.";
  }
  else
  {
    return;
  }
}

ObjectEffectLadder::ObjectEffectLadder()
{
  m_types<<ClassEnum::OBJECTEFFECTLADDER;
}

bool ObjectEffectLadder::operator==(const ObjectEffectLadder &compared)
{
  if(monsterCount == compared.monsterCount)
  return true;
  
  return false;
}

