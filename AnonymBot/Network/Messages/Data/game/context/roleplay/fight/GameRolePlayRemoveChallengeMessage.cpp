#include "GameRolePlayRemoveChallengeMessage.h"

void GameRolePlayRemoveChallengeMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayRemoveChallengeMessage(param1);
}

void GameRolePlayRemoveChallengeMessage::serializeAs_GameRolePlayRemoveChallengeMessage(Writer *param1)
{
  param1->writeInt((int)this->fightId);
}

void GameRolePlayRemoveChallengeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayRemoveChallengeMessage(param1);
}

void GameRolePlayRemoveChallengeMessage::deserializeAs_GameRolePlayRemoveChallengeMessage(Reader *param1)
{
  this->fightId = param1->readInt();
}

GameRolePlayRemoveChallengeMessage::GameRolePlayRemoveChallengeMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYREMOVECHALLENGEMESSAGE;
}

