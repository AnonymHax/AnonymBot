#include "GameFightNewRoundMessage.h"

void GameFightNewRoundMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightNewRoundMessage(param1);
}

void GameFightNewRoundMessage::serializeAs_GameFightNewRoundMessage(Writer *param1)
{
  if(this->roundNumber < 0)
  {
    qDebug()<<"ERREUR - GameFightNewRoundMessage -"<<"Forbidden value (" << this->roundNumber << ") on element roundNumber.";
  }
  else
  {
    param1->writeVarInt((int)this->roundNumber);
    return;
  }
}

void GameFightNewRoundMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightNewRoundMessage(param1);
}

void GameFightNewRoundMessage::deserializeAs_GameFightNewRoundMessage(Reader *param1)
{
  this->roundNumber = param1->readVarUhInt();
  if(this->roundNumber < 0)
  {
    qDebug()<<"ERREUR - GameFightNewRoundMessage -"<<"Forbidden value (" << this->roundNumber << ") on element of GameFightNewRoundMessage.roundNumber.";
  }
  else
  {
    return;
  }
}

GameFightNewRoundMessage::GameFightNewRoundMessage()
{
  m_type = MessageEnum::GAMEFIGHTNEWROUNDMESSAGE;
}

