#include "GameActionFightVanishMessage.h"

void GameActionFightVanishMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightVanishMessage(param1);
}

void GameActionFightVanishMessage::serializeAs_GameActionFightVanishMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightVanishMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameActionFightVanishMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightVanishMessage(param1);
}

void GameActionFightVanishMessage::deserializeAs_GameActionFightVanishMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightVanishMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightVanishMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameActionFightVanishMessage::GameActionFightVanishMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTVANISHMESSAGE;
}

