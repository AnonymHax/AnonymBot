#include "GameRolePlayArenaFightAnswerMessage.h"

void GameRolePlayArenaFightAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaFightAnswerMessage(param1);
}

void GameRolePlayArenaFightAnswerMessage::serializeAs_GameRolePlayArenaFightAnswerMessage(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  param1->writeBool(this->accept);
}

void GameRolePlayArenaFightAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaFightAnswerMessage(param1);
}

void GameRolePlayArenaFightAnswerMessage::deserializeAs_GameRolePlayArenaFightAnswerMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  this->accept = param1->readBool();
}

GameRolePlayArenaFightAnswerMessage::GameRolePlayArenaFightAnswerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAFIGHTANSWERMESSAGE;
}

