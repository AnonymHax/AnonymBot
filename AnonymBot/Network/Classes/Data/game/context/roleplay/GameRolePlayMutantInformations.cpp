#include "GameRolePlayMutantInformations.h"

void GameRolePlayMutantInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayMutantInformations(param1);
}

void GameRolePlayMutantInformations::serializeAs_GameRolePlayMutantInformations(Writer *param1)
{
  GameRolePlayHumanoidInformations::serializeAs_GameRolePlayHumanoidInformations(param1);
  if(this->monsterId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMutantInformations -"<<"Forbidden value (" << this->monsterId << ") on element monsterId.";
  }
  else
  {
    param1->writeVarShort((int)this->monsterId);
    param1->writeByte(this->powerLevel);
    return;
  }
}

void GameRolePlayMutantInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayMutantInformations(param1);
}

void GameRolePlayMutantInformations::deserializeAs_GameRolePlayMutantInformations(Reader *param1)
{
  GameRolePlayHumanoidInformations::deserialize(param1);
  this->monsterId = param1->readVarUhShort();
  if(this->monsterId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMutantInformations -"<<"Forbidden value (" << this->monsterId << ") on element of GameRolePlayMutantInformations.monsterId.";
  }
  else
  {
    this->powerLevel = param1->readByte();
    return;
  }
}

GameRolePlayMutantInformations::GameRolePlayMutantInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYMUTANTINFORMATIONS;
}

bool GameRolePlayMutantInformations::operator==(const GameRolePlayMutantInformations &compared)
{
  if(monsterId == compared.monsterId)
  if(powerLevel == compared.powerLevel)
  return true;
  
  return false;
}

