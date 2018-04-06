#include "GameFightTurnFinishMessage.h"

void GameFightTurnFinishMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnFinishMessage(param1);
}

void GameFightTurnFinishMessage::serializeAs_GameFightTurnFinishMessage(Writer *param1)
{
  param1->writeBool(this->isAfk);
}

void GameFightTurnFinishMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnFinishMessage(param1);
}

void GameFightTurnFinishMessage::deserializeAs_GameFightTurnFinishMessage(Reader *param1)
{
  this->isAfk = param1->readBool();
}

GameFightTurnFinishMessage::GameFightTurnFinishMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNFINISHMESSAGE;
}

