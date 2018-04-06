#include "GameFightLeaveMessage.h"

void GameFightLeaveMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightLeaveMessage(param1);
}

void GameFightLeaveMessage::serializeAs_GameFightLeaveMessage(Writer *param1)
{
  if(this->charId < -9.007199254740992E15 || this->charId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightLeaveMessage -"<<"Forbidden value (" << this->charId << ") on element charId.";
  }
  else
  {
    param1->writeDouble(this->charId);
    return;
  }
}

void GameFightLeaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightLeaveMessage(param1);
}

void GameFightLeaveMessage::deserializeAs_GameFightLeaveMessage(Reader *param1)
{
  this->charId = param1->readDouble();
  if(this->charId < -9.007199254740992E15 || this->charId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightLeaveMessage -"<<"Forbidden value (" << this->charId << ") on element of GameFightLeaveMessage.charId.";
  }
  else
  {
    return;
  }
}

GameFightLeaveMessage::GameFightLeaveMessage()
{
  m_type = MessageEnum::GAMEFIGHTLEAVEMESSAGE;
}

