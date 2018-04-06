#include "GameFightMutantInformations.h"

void GameFightMutantInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightMutantInformations(param1);
}

void GameFightMutantInformations::serializeAs_GameFightMutantInformations(Writer *param1)
{
  GameFightFighterNamedInformations::serializeAs_GameFightFighterNamedInformations(param1);
  if(this->powerLevel < 0)
  {
    qDebug()<<"ERREUR - GameFightMutantInformations -"<<"Forbidden value (" << this->powerLevel << ") on element powerLevel.";
  }
  else
  {
    param1->writeByte(this->powerLevel);
    return;
  }
}

void GameFightMutantInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightMutantInformations(param1);
}

void GameFightMutantInformations::deserializeAs_GameFightMutantInformations(Reader *param1)
{
  GameFightFighterNamedInformations::deserialize(param1);
  this->powerLevel = param1->readByte();
  if(this->powerLevel < 0)
  {
    qDebug()<<"ERREUR - GameFightMutantInformations -"<<"Forbidden value (" << this->powerLevel << ") on element of GameFightMutantInformations.powerLevel.";
  }
  else
  {
    return;
  }
}

GameFightMutantInformations::GameFightMutantInformations()
{
  m_types<<ClassEnum::GAMEFIGHTMUTANTINFORMATIONS;
}

bool GameFightMutantInformations::operator==(const GameFightMutantInformations &compared)
{
  if(powerLevel == compared.powerLevel)
  return true;
  
  return false;
}

