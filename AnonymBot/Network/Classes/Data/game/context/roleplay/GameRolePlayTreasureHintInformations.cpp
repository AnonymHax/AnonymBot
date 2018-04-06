#include "GameRolePlayTreasureHintInformations.h"

void GameRolePlayTreasureHintInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayTreasureHintInformations(param1);
}

void GameRolePlayTreasureHintInformations::serializeAs_GameRolePlayTreasureHintInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayTreasureHintInformations -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  else
  {
    param1->writeVarShort((int)this->npcId);
    return;
  }
}

void GameRolePlayTreasureHintInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayTreasureHintInformations(param1);
}

void GameRolePlayTreasureHintInformations::deserializeAs_GameRolePlayTreasureHintInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  this->npcId = param1->readVarUhShort();
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayTreasureHintInformations -"<<"Forbidden value (" << this->npcId << ") on element of GameRolePlayTreasureHintInformations.npcId.";
  }
  else
  {
    return;
  }
}

GameRolePlayTreasureHintInformations::GameRolePlayTreasureHintInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYTREASUREHINTINFORMATIONS;
}

bool GameRolePlayTreasureHintInformations::operator==(const GameRolePlayTreasureHintInformations &compared)
{
  if(npcId == compared.npcId)
  return true;
  
  return false;
}

