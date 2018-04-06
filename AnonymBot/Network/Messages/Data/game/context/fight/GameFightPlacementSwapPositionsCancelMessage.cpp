#include "GameFightPlacementSwapPositionsCancelMessage.h"

void GameFightPlacementSwapPositionsCancelMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementSwapPositionsCancelMessage(param1);
}

void GameFightPlacementSwapPositionsCancelMessage::serializeAs_GameFightPlacementSwapPositionsCancelMessage(Writer *param1)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeInt((int)this->requestId);
    return;
  }
}

void GameFightPlacementSwapPositionsCancelMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementSwapPositionsCancelMessage(param1);
}

void GameFightPlacementSwapPositionsCancelMessage::deserializeAs_GameFightPlacementSwapPositionsCancelMessage(Reader *param1)
{
  this->requestId = param1->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsCancelMessage.requestId.";
  }
  else
  {
    return;
  }
}

GameFightPlacementSwapPositionsCancelMessage::GameFightPlacementSwapPositionsCancelMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE;
}

