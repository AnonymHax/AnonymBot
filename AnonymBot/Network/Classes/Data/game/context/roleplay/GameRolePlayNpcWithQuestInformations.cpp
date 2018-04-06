#include "GameRolePlayNpcWithQuestInformations.h"

void GameRolePlayNpcWithQuestInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayNpcWithQuestInformations(param1);
}

void GameRolePlayNpcWithQuestInformations::serializeAs_GameRolePlayNpcWithQuestInformations(Writer *param1)
{
  GameRolePlayNpcInformations::serializeAs_GameRolePlayNpcInformations(param1);
  this->questFlag.serializeAs_GameRolePlayNpcQuestFlag(param1);
}

void GameRolePlayNpcWithQuestInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayNpcWithQuestInformations(param1);
}

void GameRolePlayNpcWithQuestInformations::deserializeAs_GameRolePlayNpcWithQuestInformations(Reader *param1)
{
  GameRolePlayNpcInformations::deserialize(param1);
  this->questFlag = GameRolePlayNpcQuestFlag();
  this->questFlag.deserialize(param1);
}

GameRolePlayNpcWithQuestInformations::GameRolePlayNpcWithQuestInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYNPCWITHQUESTINFORMATIONS;
}

bool GameRolePlayNpcWithQuestInformations::operator==(const GameRolePlayNpcWithQuestInformations &compared)
{
  if(questFlag == compared.questFlag)
  return true;
  
  return false;
}

