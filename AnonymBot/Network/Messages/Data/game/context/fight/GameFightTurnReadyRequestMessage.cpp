#include "GameFightTurnReadyRequestMessage.h"

void GameFightTurnReadyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnReadyRequestMessage(param1);
}

void GameFightTurnReadyRequestMessage::serializeAs_GameFightTurnReadyRequestMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnReadyRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    return;
  }
}

void GameFightTurnReadyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnReadyRequestMessage(param1);
}

void GameFightTurnReadyRequestMessage::deserializeAs_GameFightTurnReadyRequestMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnReadyRequestMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightTurnReadyRequestMessage.id.";
  }
  else
  {
    return;
  }
}

GameFightTurnReadyRequestMessage::GameFightTurnReadyRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNREADYREQUESTMESSAGE;
}

