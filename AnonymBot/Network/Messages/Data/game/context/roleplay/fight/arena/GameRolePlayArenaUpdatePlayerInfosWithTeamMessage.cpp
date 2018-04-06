#include "GameRolePlayArenaUpdatePlayerInfosWithTeamMessage.h"

void GameRolePlayArenaUpdatePlayerInfosWithTeamMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaUpdatePlayerInfosWithTeamMessage(param1);
}

void GameRolePlayArenaUpdatePlayerInfosWithTeamMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosWithTeamMessage(Writer *param1)
{
  GameRolePlayArenaUpdatePlayerInfosMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(param1);
  this->team.serializeAs_ArenaRankInfos(param1);
}

void GameRolePlayArenaUpdatePlayerInfosWithTeamMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaUpdatePlayerInfosWithTeamMessage(param1);
}

void GameRolePlayArenaUpdatePlayerInfosWithTeamMessage::deserializeAs_GameRolePlayArenaUpdatePlayerInfosWithTeamMessage(Reader *param1)
{
  GameRolePlayArenaUpdatePlayerInfosMessage::deserialize(param1);
  this->team = ArenaRankInfos();
  this->team.deserialize(param1);
}

GameRolePlayArenaUpdatePlayerInfosWithTeamMessage::GameRolePlayArenaUpdatePlayerInfosWithTeamMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSWITHTEAMMESSAGE;
}

