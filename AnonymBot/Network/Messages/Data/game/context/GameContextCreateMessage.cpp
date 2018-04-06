#include "GameContextCreateMessage.h"

void GameContextCreateMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextCreateMessage(param1);
}

void GameContextCreateMessage::serializeAs_GameContextCreateMessage(Writer *param1)
{
  param1->writeByte(this->context);
}

void GameContextCreateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextCreateMessage(param1);
}

void GameContextCreateMessage::deserializeAs_GameContextCreateMessage(Reader *param1)
{
  this->context = param1->readByte();
  if(this->context < 0)
  {
    qDebug()<<"ERREUR - GameContextCreateMessage -"<<"Forbidden value (" << this->context << ") on element of GameContextCreateMessage.context.";
  }
  else
  {
    return;
  }
}

GameContextCreateMessage::GameContextCreateMessage()
{
  m_type = MessageEnum::GAMECONTEXTCREATEMESSAGE;
}

