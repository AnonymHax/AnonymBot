#include "GameFightTurnEndMessage.h"

void GameFightTurnEndMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnEndMessage(param1);
}

void GameFightTurnEndMessage::serializeAs_GameFightTurnEndMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnEndMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    return;
  }
}

void GameFightTurnEndMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnEndMessage(param1);
}

void GameFightTurnEndMessage::deserializeAs_GameFightTurnEndMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnEndMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightTurnEndMessage.id.";
  }
  else
  {
    return;
  }
}

GameFightTurnEndMessage::GameFightTurnEndMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNENDMESSAGE;
}

