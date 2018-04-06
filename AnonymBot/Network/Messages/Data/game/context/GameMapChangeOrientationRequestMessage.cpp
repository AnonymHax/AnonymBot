#include "GameMapChangeOrientationRequestMessage.h"

void GameMapChangeOrientationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapChangeOrientationRequestMessage(param1);
}

void GameMapChangeOrientationRequestMessage::serializeAs_GameMapChangeOrientationRequestMessage(Writer *param1)
{
  param1->writeByte(this->direction);
}

void GameMapChangeOrientationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapChangeOrientationRequestMessage(param1);
}

void GameMapChangeOrientationRequestMessage::deserializeAs_GameMapChangeOrientationRequestMessage(Reader *param1)
{
  this->direction = param1->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - GameMapChangeOrientationRequestMessage -"<<"Forbidden value (" << this->direction << ") on element of GameMapChangeOrientationRequestMessage.direction.";
  }
  else
  {
    return;
  }
}

GameMapChangeOrientationRequestMessage::GameMapChangeOrientationRequestMessage()
{
  m_type = MessageEnum::GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE;
}

