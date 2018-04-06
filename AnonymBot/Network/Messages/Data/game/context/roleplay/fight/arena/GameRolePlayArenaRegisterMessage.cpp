#include "GameRolePlayArenaRegisterMessage.h"

void GameRolePlayArenaRegisterMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaRegisterMessage(param1);
}

void GameRolePlayArenaRegisterMessage::serializeAs_GameRolePlayArenaRegisterMessage(Writer *param1)
{
  param1->writeInt((int)this->battleMode);
}

void GameRolePlayArenaRegisterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaRegisterMessage(param1);
}

void GameRolePlayArenaRegisterMessage::deserializeAs_GameRolePlayArenaRegisterMessage(Reader *param1)
{
  this->battleMode = param1->readInt();
  if(this->battleMode < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegisterMessage -"<<"Forbidden value (" << this->battleMode << ") on element of GameRolePlayArenaRegisterMessage.battleMode.";
  }
  else
  {
    return;
  }
}

GameRolePlayArenaRegisterMessage::GameRolePlayArenaRegisterMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAREGISTERMESSAGE;
}

