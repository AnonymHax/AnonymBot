#include "GameFightTurnResumeMessage.h"

void GameFightTurnResumeMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnResumeMessage(param1);
}

void GameFightTurnResumeMessage::serializeAs_GameFightTurnResumeMessage(Writer *param1)
{
  GameFightTurnStartMessage::serializeAs_GameFightTurnStartMessage(param1);
  if(this->remainingTime < 0)
  {
    qDebug()<<"ERREUR - GameFightTurnResumeMessage -"<<"Forbidden value (" << this->remainingTime << ") on element remainingTime.";
  }
  else
  {
    param1->writeVarInt((int)this->remainingTime);
    return;
  }
}

void GameFightTurnResumeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnResumeMessage(param1);
}

void GameFightTurnResumeMessage::deserializeAs_GameFightTurnResumeMessage(Reader *param1)
{
  GameFightTurnStartMessage::deserialize(param1);
  this->remainingTime = param1->readVarUhInt();
  if(this->remainingTime < 0)
  {
    qDebug()<<"ERREUR - GameFightTurnResumeMessage -"<<"Forbidden value (" << this->remainingTime << ") on element of GameFightTurnResumeMessage.remainingTime.";
  }
  else
  {
    return;
  }
}

GameFightTurnResumeMessage::GameFightTurnResumeMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNRESUMEMESSAGE;
}

