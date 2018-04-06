#include "GameFightFighterMonsterLightInformations.h"

void GameFightFighterMonsterLightInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterMonsterLightInformations(param1);
}

void GameFightFighterMonsterLightInformations::serializeAs_GameFightFighterMonsterLightInformations(Writer *param1)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(param1);
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterMonsterLightInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element creatureGenericId.";
  }
  else
  {
    param1->writeVarShort((int)this->creatureGenericId);
    return;
  }
}

void GameFightFighterMonsterLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterMonsterLightInformations(param1);
}

void GameFightFighterMonsterLightInformations::deserializeAs_GameFightFighterMonsterLightInformations(Reader *param1)
{
  GameFightFighterLightInformations::deserialize(param1);
  this->creatureGenericId = param1->readVarUhShort();
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterMonsterLightInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element of GameFightFighterMonsterLightInformations.creatureGenericId.";
  }
  else
  {
    return;
  }
}

GameFightFighterMonsterLightInformations::GameFightFighterMonsterLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS;
}

bool GameFightFighterMonsterLightInformations::operator==(const GameFightFighterMonsterLightInformations &compared)
{
  if(creatureGenericId == compared.creatureGenericId)
  return true;
  
  return false;
}

