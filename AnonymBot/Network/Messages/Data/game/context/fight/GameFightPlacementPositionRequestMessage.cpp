#include "GameFightPlacementPositionRequestMessage.h"

void GameFightPlacementPositionRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementPositionRequestMessage(param1);
}

void GameFightPlacementPositionRequestMessage::serializeAs_GameFightPlacementPositionRequestMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementPositionRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void GameFightPlacementPositionRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementPositionRequestMessage(param1);
}

void GameFightPlacementPositionRequestMessage::deserializeAs_GameFightPlacementPositionRequestMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementPositionRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameFightPlacementPositionRequestMessage.cellId.";
  }
  else
  {
    return;
  }
}

GameFightPlacementPositionRequestMessage::GameFightPlacementPositionRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE;
}

