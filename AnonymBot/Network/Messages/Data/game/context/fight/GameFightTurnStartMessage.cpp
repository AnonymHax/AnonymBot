#include "GameFightTurnStartMessage.h"

void GameFightTurnStartMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnStartMessage(param1);
}

void GameFightTurnStartMessage::serializeAs_GameFightTurnStartMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    if(this->waitTime < 0)
    {
      qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->waitTime << ") on element waitTime.";
    }
    else
    {
      param1->writeVarInt((int)this->waitTime);
      return;
    }
  }
}

void GameFightTurnStartMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnStartMessage(param1);
}

void GameFightTurnStartMessage::deserializeAs_GameFightTurnStartMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightTurnStartMessage.id.";
  }
  else
  {
    this->waitTime = param1->readVarUhInt();
    if(this->waitTime < 0)
    {
      qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->waitTime << ") on element of GameFightTurnStartMessage.waitTime.";
    }
    else
    {
      return;
    }
  }
}

GameFightTurnStartMessage::GameFightTurnStartMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNSTARTMESSAGE;
}

