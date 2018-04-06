#include "GameMapMovementCancelMessage.h"

void GameMapMovementCancelMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapMovementCancelMessage(param1);
}

void GameMapMovementCancelMessage::serializeAs_GameMapMovementCancelMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameMapMovementCancelMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void GameMapMovementCancelMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapMovementCancelMessage(param1);
}

void GameMapMovementCancelMessage::deserializeAs_GameMapMovementCancelMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameMapMovementCancelMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameMapMovementCancelMessage.cellId.";
  }
  else
  {
    return;
  }
}

GameMapMovementCancelMessage::GameMapMovementCancelMessage()
{
  m_type = MessageEnum::GAMEMAPMOVEMENTCANCELMESSAGE;
}

