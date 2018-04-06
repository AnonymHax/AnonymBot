#include "GameContextReadyMessage.h"

void GameContextReadyMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextReadyMessage(param1);
}

void GameContextReadyMessage::serializeAs_GameContextReadyMessage(Writer *param1)
{
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - GameContextReadyMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void GameContextReadyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextReadyMessage(param1);
}

void GameContextReadyMessage::deserializeAs_GameContextReadyMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - GameContextReadyMessage -"<<"Forbidden value (" << this->mapId << ") on element of GameContextReadyMessage.mapId.";
  }
  else
  {
    return;
  }
}

GameContextReadyMessage::GameContextReadyMessage()
{
  m_type = MessageEnum::GAMECONTEXTREADYMESSAGE;
}

