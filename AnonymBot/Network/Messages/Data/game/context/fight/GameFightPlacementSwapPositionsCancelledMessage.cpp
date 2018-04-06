#include "GameFightPlacementSwapPositionsCancelledMessage.h"

void GameFightPlacementSwapPositionsCancelledMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementSwapPositionsCancelledMessage(param1);
}

void GameFightPlacementSwapPositionsCancelledMessage::serializeAs_GameFightPlacementSwapPositionsCancelledMessage(Writer *param1)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeInt((int)this->requestId);
    if(this->cancellerId < -9.007199254740992E15 || this->cancellerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->cancellerId << ") on element cancellerId.";
    }
    else
    {
      param1->writeDouble(this->cancellerId);
      return;
    }
  }
}

void GameFightPlacementSwapPositionsCancelledMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementSwapPositionsCancelledMessage(param1);
}

void GameFightPlacementSwapPositionsCancelledMessage::deserializeAs_GameFightPlacementSwapPositionsCancelledMessage(Reader *param1)
{
  this->requestId = param1->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsCancelledMessage.requestId.";
  }
  else
  {
    this->cancellerId = param1->readDouble();
    if(this->cancellerId < -9.007199254740992E15 || this->cancellerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->cancellerId << ") on element of GameFightPlacementSwapPositionsCancelledMessage.cancellerId.";
    }
    else
    {
      return;
    }
  }
}

GameFightPlacementSwapPositionsCancelledMessage::GameFightPlacementSwapPositionsCancelledMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE;
}

