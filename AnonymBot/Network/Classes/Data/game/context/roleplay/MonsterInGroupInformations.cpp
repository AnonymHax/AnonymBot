#include "MonsterInGroupInformations.h"

void MonsterInGroupInformations::serialize(Writer *param1)
{
  this->serializeAs_MonsterInGroupInformations(param1);
}

void MonsterInGroupInformations::serializeAs_MonsterInGroupInformations(Writer *param1)
{
  MonsterInGroupLightInformations::serializeAs_MonsterInGroupLightInformations(param1);
  this->look->serializeAs_EntityLook(param1);
}

void MonsterInGroupInformations::deserialize(Reader *param1)
{
  this->deserializeAs_MonsterInGroupInformations(param1);
}

void MonsterInGroupInformations::deserializeAs_MonsterInGroupInformations(Reader *param1)
{
  MonsterInGroupLightInformations::deserialize(param1);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(param1);
}

MonsterInGroupInformations::MonsterInGroupInformations()
{
  m_types<<ClassEnum::MONSTERINGROUPINFORMATIONS;
}

bool MonsterInGroupInformations::operator==(const MonsterInGroupInformations &compared)
{
  if(look == compared.look)
  return true;
  
  return false;
}

