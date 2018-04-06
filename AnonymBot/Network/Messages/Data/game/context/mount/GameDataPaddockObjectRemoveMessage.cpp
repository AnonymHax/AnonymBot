#include "GameDataPaddockObjectRemoveMessage.h"

void GameDataPaddockObjectRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_GameDataPaddockObjectRemoveMessage(param1);
}

void GameDataPaddockObjectRemoveMessage::serializeAs_GameDataPaddockObjectRemoveMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameDataPaddockObjectRemoveMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void GameDataPaddockObjectRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameDataPaddockObjectRemoveMessage(param1);
}

void GameDataPaddockObjectRemoveMessage::deserializeAs_GameDataPaddockObjectRemoveMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameDataPaddockObjectRemoveMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameDataPaddockObjectRemoveMessage.cellId.";
  }
  else
  {
    return;
  }
}

GameDataPaddockObjectRemoveMessage::GameDataPaddockObjectRemoveMessage()
{
  m_type = MessageEnum::GAMEDATAPADDOCKOBJECTREMOVEMESSAGE;
}

