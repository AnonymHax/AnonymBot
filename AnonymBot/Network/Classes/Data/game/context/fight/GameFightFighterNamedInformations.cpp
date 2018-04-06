#include "GameFightFighterNamedInformations.h"

void GameFightFighterNamedInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterNamedInformations(param1);
}

void GameFightFighterNamedInformations::serializeAs_GameFightFighterNamedInformations(Writer *param1)
{
  GameFightFighterInformations::serializeAs_GameFightFighterInformations(param1);
  param1->writeUTF(this->name);
  this->status->serializeAs_PlayerStatus(param1);
}

void GameFightFighterNamedInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterNamedInformations(param1);
}

void GameFightFighterNamedInformations::deserializeAs_GameFightFighterNamedInformations(Reader *param1)
{
  GameFightFighterInformations::deserialize(param1);
  this->name = param1->readUTF();
  this->status = QSharedPointer<PlayerStatus>(new PlayerStatus() );
  this->status->deserialize(param1);
}

GameFightFighterNamedInformations::GameFightFighterNamedInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERNAMEDINFORMATIONS;
}

bool GameFightFighterNamedInformations::operator==(const GameFightFighterNamedInformations &compared)
{
  if(name == compared.name)
  if(status == compared.status)
  return true;
  
  return false;
}

