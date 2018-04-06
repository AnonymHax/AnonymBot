#include "GameRolePlayNamedActorInformations.h"

void GameRolePlayNamedActorInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayNamedActorInformations(param1);
}

void GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  param1->writeUTF(this->name);
}

void GameRolePlayNamedActorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayNamedActorInformations(param1);
}

void GameRolePlayNamedActorInformations::deserializeAs_GameRolePlayNamedActorInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  this->name = param1->readUTF();
}

GameRolePlayNamedActorInformations::GameRolePlayNamedActorInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYNAMEDACTORINFORMATIONS;
}

bool GameRolePlayNamedActorInformations::operator==(const GameRolePlayNamedActorInformations &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

