#include "GameFightAIInformations.h"

void GameFightAIInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightAIInformations(param1);
}

void GameFightAIInformations::serializeAs_GameFightAIInformations(Writer *param1)
{
  GameFightFighterInformations::serializeAs_GameFightFighterInformations(param1);
}

void GameFightAIInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightAIInformations(param1);
}

void GameFightAIInformations::deserializeAs_GameFightAIInformations(Reader *param1)
{
  GameFightFighterInformations::deserialize(param1);
}

GameFightAIInformations::GameFightAIInformations()
{
  m_types<<ClassEnum::GAMEFIGHTAIINFORMATIONS;
}

bool GameFightAIInformations::operator==(const GameFightAIInformations &compared)
{
  return true;
}

