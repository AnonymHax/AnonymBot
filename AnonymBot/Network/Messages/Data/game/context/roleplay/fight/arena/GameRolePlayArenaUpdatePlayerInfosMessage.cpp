#include "GameRolePlayArenaUpdatePlayerInfosMessage.h"

void GameRolePlayArenaUpdatePlayerInfosMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(param1);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Writer *param1)
{
  this->solo.serializeAs_ArenaRankInfos(param1);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(param1);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Reader *param1)
{
  this->solo = ArenaRankInfos();
  this->solo.deserialize(param1);
}

GameRolePlayArenaUpdatePlayerInfosMessage::GameRolePlayArenaUpdatePlayerInfosMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE;
}

