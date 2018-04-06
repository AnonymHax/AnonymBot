#include "GameRolePlayPortalInformations.h"

void GameRolePlayPortalInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPortalInformations(param1);
}

void GameRolePlayPortalInformations::serializeAs_GameRolePlayPortalInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  param1->writeShort((short)this->portal->getTypes().last());
  this->portal->serialize(param1);
}

void GameRolePlayPortalInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPortalInformations(param1);
}

void GameRolePlayPortalInformations::deserializeAs_GameRolePlayPortalInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  this->portal = qSharedPointerCast<PortalInformation>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->portal->deserialize(param1);
}

GameRolePlayPortalInformations::GameRolePlayPortalInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYPORTALINFORMATIONS;
}

bool GameRolePlayPortalInformations::operator==(const GameRolePlayPortalInformations &compared)
{
  if(portal == compared.portal)
  return true;
  
  return false;
}

