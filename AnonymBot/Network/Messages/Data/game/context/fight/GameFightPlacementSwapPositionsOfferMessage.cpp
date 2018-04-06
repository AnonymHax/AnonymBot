#include "GameFightPlacementSwapPositionsOfferMessage.h"

void GameFightPlacementSwapPositionsOfferMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementSwapPositionsOfferMessage(param1);
}

void GameFightPlacementSwapPositionsOfferMessage::serializeAs_GameFightPlacementSwapPositionsOfferMessage(Writer *param1)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeInt((int)this->requestId);
    if(this->requesterId < -9.007199254740992E15 || this->requesterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
    }
    else
    {
      param1->writeDouble(this->requesterId);
      if(this->requesterCellId < 0 || this->requesterCellId > 559)
      {
        qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterCellId << ") on element requesterCellId.";
      }
      else
      {
        param1->writeVarShort((int)this->requesterCellId);
        if(this->requestedId < -9.007199254740992E15 || this->requestedId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedId << ") on element requestedId.";
        }
        else
        {
          param1->writeDouble(this->requestedId);
          if(this->requestedCellId < 0 || this->requestedCellId > 559)
          {
            qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedCellId << ") on element requestedCellId.";
          }
          else
          {
            param1->writeVarShort((int)this->requestedCellId);
            return;
          }
        }
      }
    }
  }
}

void GameFightPlacementSwapPositionsOfferMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementSwapPositionsOfferMessage(param1);
}

void GameFightPlacementSwapPositionsOfferMessage::deserializeAs_GameFightPlacementSwapPositionsOfferMessage(Reader *param1)
{
  this->requestId = param1->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requestId.";
  }
  else
  {
    this->requesterId = param1->readDouble();
    if(this->requesterId < -9.007199254740992E15 || this->requesterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requesterId.";
    }
    else
    {
      this->requesterCellId = param1->readVarUhShort();
      if(this->requesterCellId < 0 || this->requesterCellId > 559)
      {
        qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterCellId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requesterCellId.";
      }
      else
      {
        this->requestedId = param1->readDouble();
        if(this->requestedId < -9.007199254740992E15 || this->requestedId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requestedId.";
        }
        else
        {
          this->requestedCellId = param1->readVarUhShort();
          if(this->requestedCellId < 0 || this->requestedCellId > 559)
          {
            qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedCellId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requestedCellId.";
          }
          else
          {
            return;
          }
        }
      }
    }
  }
}

GameFightPlacementSwapPositionsOfferMessage::GameFightPlacementSwapPositionsOfferMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE;
}

