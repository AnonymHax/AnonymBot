#include "GameRolePlayPlayerFightFriendlyAnswerMessage.h"

void GameRolePlayPlayerFightFriendlyAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(param1);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::serializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  param1->writeBool(this->accept);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(param1);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::deserializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  this->accept = param1->readBool();
}

GameRolePlayPlayerFightFriendlyAnswerMessage::GameRolePlayPlayerFightFriendlyAnswerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE;
}

