#include "GameFightOptionToggleMessage.h"

void GameFightOptionToggleMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightOptionToggleMessage(param1);
}

void GameFightOptionToggleMessage::serializeAs_GameFightOptionToggleMessage(Writer *param1)
{
  param1->writeByte(this->option);
}

void GameFightOptionToggleMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightOptionToggleMessage(param1);
}

void GameFightOptionToggleMessage::deserializeAs_GameFightOptionToggleMessage(Reader *param1)
{
  this->option = param1->readByte();
  if(this->option < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionToggleMessage -"<<"Forbidden value (" << this->option << ") on element of GameFightOptionToggleMessage.option.";
  }
  else
  {
    return;
  }
}

GameFightOptionToggleMessage::GameFightOptionToggleMessage()
{
  m_type = MessageEnum::GAMEFIGHTOPTIONTOGGLEMESSAGE;
}

