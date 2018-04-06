#include "GameFightFighterNamedLightInformations.h"

void GameFightFighterNamedLightInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterNamedLightInformations(param1);
}

void GameFightFighterNamedLightInformations::serializeAs_GameFightFighterNamedLightInformations(Writer *param1)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(param1);
  param1->writeUTF(this->name);
}

void GameFightFighterNamedLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterNamedLightInformations(param1);
}

void GameFightFighterNamedLightInformations::deserializeAs_GameFightFighterNamedLightInformations(Reader *param1)
{
  GameFightFighterLightInformations::deserialize(param1);
  this->name = param1->readUTF();
}

GameFightFighterNamedLightInformations::GameFightFighterNamedLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS;
}

bool GameFightFighterNamedLightInformations::operator==(const GameFightFighterNamedLightInformations &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

