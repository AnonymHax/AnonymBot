#include "GameFightMinimalStatsPreparation.h"

void GameFightMinimalStatsPreparation::serialize(Writer *param1)
{
  this->serializeAs_GameFightMinimalStatsPreparation(param1);
}

void GameFightMinimalStatsPreparation::serializeAs_GameFightMinimalStatsPreparation(Writer *param1)
{
  GameFightMinimalStats::serializeAs_GameFightMinimalStats(param1);
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStatsPreparation -"<<"Forbidden value (" << this->initiative << ") on element initiative.";
  }
  else
  {
    param1->writeVarInt((int)this->initiative);
    return;
  }
}

void GameFightMinimalStatsPreparation::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightMinimalStatsPreparation(param1);
}

void GameFightMinimalStatsPreparation::deserializeAs_GameFightMinimalStatsPreparation(Reader *param1)
{
  GameFightMinimalStats::deserialize(param1);
  this->initiative = param1->readVarUhInt();
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStatsPreparation -"<<"Forbidden value (" << this->initiative << ") on element of GameFightMinimalStatsPreparation.initiative.";
  }
  else
  {
    return;
  }
}

GameFightMinimalStatsPreparation::GameFightMinimalStatsPreparation()
{
  m_types<<ClassEnum::GAMEFIGHTMINIMALSTATSPREPARATION;
}

bool GameFightMinimalStatsPreparation::operator==(const GameFightMinimalStatsPreparation &compared)
{
  if(initiative == compared.initiative)
  return true;
  
  return false;
}

