#include "GameActionFightMarkCellsMessage.h"

void GameActionFightMarkCellsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightMarkCellsMessage(param1);
}

void GameActionFightMarkCellsMessage::serializeAs_GameActionFightMarkCellsMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  this->mark.serializeAs_GameActionMark(param1);
}

void GameActionFightMarkCellsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightMarkCellsMessage(param1);
}

void GameActionFightMarkCellsMessage::deserializeAs_GameActionFightMarkCellsMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->mark = GameActionMark();
  this->mark.deserialize(param1);
}

GameActionFightMarkCellsMessage::GameActionFightMarkCellsMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTMARKCELLSMESSAGE;
}

