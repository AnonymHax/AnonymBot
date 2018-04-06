#include "GameRolePlayActorInformations.h"

void GameRolePlayActorInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayActorInformations(param1);
}

void GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(Writer *param1)
{
  GameContextActorInformations::serializeAs_GameContextActorInformations(param1);
}

void GameRolePlayActorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayActorInformations(param1);
}

void GameRolePlayActorInformations::deserializeAs_GameRolePlayActorInformations(Reader *param1)
{
  GameContextActorInformations::deserialize(param1);
}

GameRolePlayActorInformations::GameRolePlayActorInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYACTORINFORMATIONS;
}

bool GameRolePlayActorInformations::operator==(const GameRolePlayActorInformations &compared)
{
  return true;
}

