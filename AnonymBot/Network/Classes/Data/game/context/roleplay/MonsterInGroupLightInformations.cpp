#include "MonsterInGroupLightInformations.h"

void MonsterInGroupLightInformations::serialize(Writer *param1)
{
  this->serializeAs_MonsterInGroupLightInformations(param1);
}

void MonsterInGroupLightInformations::serializeAs_MonsterInGroupLightInformations(Writer *param1)
{
  param1->writeInt((int)this->creatureGenericId);
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - MonsterInGroupLightInformations -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  else
  {
    param1->writeByte(this->grade);
    return;
  }
}

void MonsterInGroupLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_MonsterInGroupLightInformations(param1);
}

void MonsterInGroupLightInformations::deserializeAs_MonsterInGroupLightInformations(Reader *param1)
{
  this->creatureGenericId = param1->readInt();
  this->grade = param1->readByte();
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - MonsterInGroupLightInformations -"<<"Forbidden value (" << this->grade << ") on element of MonsterInGroupLightInformations.grade.";
  }
  else
  {
    return;
  }
}

MonsterInGroupLightInformations::MonsterInGroupLightInformations()
{
  m_types<<ClassEnum::MONSTERINGROUPLIGHTINFORMATIONS;
}

bool MonsterInGroupLightInformations::operator==(const MonsterInGroupLightInformations &compared)
{
  if(creatureGenericId == compared.creatureGenericId)
  if(grade == compared.grade)
  return true;
  
  return false;
}

