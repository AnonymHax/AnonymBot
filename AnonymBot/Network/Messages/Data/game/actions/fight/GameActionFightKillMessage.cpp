#include "GameActionFightKillMessage.h"

void GameActionFightKillMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightKillMessage(param1);
}

void GameActionFightKillMessage::serializeAs_GameActionFightKillMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightKillMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameActionFightKillMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightKillMessage(param1);
}

void GameActionFightKillMessage::deserializeAs_GameActionFightKillMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightKillMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightKillMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameActionFightKillMessage::GameActionFightKillMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTKILLMESSAGE;
}

