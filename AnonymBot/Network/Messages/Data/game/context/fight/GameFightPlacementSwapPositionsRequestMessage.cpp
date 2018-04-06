#include "GameFightPlacementSwapPositionsRequestMessage.h"

void GameFightPlacementSwapPositionsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementSwapPositionsRequestMessage(param1);
}

void GameFightPlacementSwapPositionsRequestMessage::serializeAs_GameFightPlacementSwapPositionsRequestMessage(Writer *param1)
{
  GameFightPlacementPositionRequestMessage::serializeAs_GameFightPlacementPositionRequestMessage(param1);
  if(this->requestedId < -9.007199254740992E15 || this->requestedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsRequestMessage -"<<"Forbidden value (" << this->requestedId << ") on element requestedId.";
  }
  else
  {
    param1->writeDouble(this->requestedId);
    return;
  }
}

void GameFightPlacementSwapPositionsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementSwapPositionsRequestMessage(param1);
}

void GameFightPlacementSwapPositionsRequestMessage::deserializeAs_GameFightPlacementSwapPositionsRequestMessage(Reader *param1)
{
  GameFightPlacementPositionRequestMessage::deserialize(param1);
  this->requestedId = param1->readDouble();
  if(this->requestedId < -9.007199254740992E15 || this->requestedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsRequestMessage -"<<"Forbidden value (" << this->requestedId << ") on element of GameFightPlacementSwapPositionsRequestMessage.requestedId.";
  }
  else
  {
    return;
  }
}

GameFightPlacementSwapPositionsRequestMessage::GameFightPlacementSwapPositionsRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE;
}

