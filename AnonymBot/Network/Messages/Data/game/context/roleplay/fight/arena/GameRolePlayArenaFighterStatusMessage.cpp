#include "GameRolePlayArenaFighterStatusMessage.h"

void GameRolePlayArenaFighterStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaFighterStatusMessage(param1);
}

void GameRolePlayArenaFighterStatusMessage::serializeAs_GameRolePlayArenaFighterStatusMessage(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  param1->writeInt((int)this->playerId);
  param1->writeBool(this->accepted);
}

void GameRolePlayArenaFighterStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaFighterStatusMessage(param1);
}

void GameRolePlayArenaFighterStatusMessage::deserializeAs_GameRolePlayArenaFighterStatusMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  this->playerId = param1->readInt();
  this->accepted = param1->readBool();
}

GameRolePlayArenaFighterStatusMessage::GameRolePlayArenaFighterStatusMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE;
}

