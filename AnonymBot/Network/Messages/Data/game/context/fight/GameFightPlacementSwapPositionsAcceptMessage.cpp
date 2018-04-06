#include "GameFightPlacementSwapPositionsAcceptMessage.h"

void GameFightPlacementSwapPositionsAcceptMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementSwapPositionsAcceptMessage(param1);
}

void GameFightPlacementSwapPositionsAcceptMessage::serializeAs_GameFightPlacementSwapPositionsAcceptMessage(Writer *param1)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsAcceptMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeInt((int)this->requestId);
    return;
  }
}

void GameFightPlacementSwapPositionsAcceptMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementSwapPositionsAcceptMessage(param1);
}

void GameFightPlacementSwapPositionsAcceptMessage::deserializeAs_GameFightPlacementSwapPositionsAcceptMessage(Reader *param1)
{
  this->requestId = param1->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsAcceptMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsAcceptMessage.requestId.";
  }
  else
  {
    return;
  }
}

GameFightPlacementSwapPositionsAcceptMessage::GameFightPlacementSwapPositionsAcceptMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE;
}

