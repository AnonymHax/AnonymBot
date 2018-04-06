#include "GameActionFightDeathMessage.h"

void GameActionFightDeathMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDeathMessage(param1);
}

void GameActionFightDeathMessage::serializeAs_GameActionFightDeathMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDeathMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameActionFightDeathMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDeathMessage(param1);
}

void GameActionFightDeathMessage::deserializeAs_GameActionFightDeathMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDeathMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDeathMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameActionFightDeathMessage::GameActionFightDeathMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDEATHMESSAGE;
}

