#include "GameFightJoinRequestMessage.h"

void GameFightJoinRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightJoinRequestMessage(param1);
}

void GameFightJoinRequestMessage::serializeAs_GameFightJoinRequestMessage(Writer *param1)
{
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightJoinRequestMessage -"<<"Forbidden value (" << this->fighterId << ") on element fighterId.";
  }
  else
  {
    param1->writeDouble(this->fighterId);
    param1->writeInt((int)this->fightId);
    return;
  }
}

void GameFightJoinRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightJoinRequestMessage(param1);
}

void GameFightJoinRequestMessage::deserializeAs_GameFightJoinRequestMessage(Reader *param1)
{
  this->fighterId = param1->readDouble();
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightJoinRequestMessage -"<<"Forbidden value (" << this->fighterId << ") on element of GameFightJoinRequestMessage.fighterId.";
  }
  else
  {
    this->fightId = param1->readInt();
    return;
  }
}

GameFightJoinRequestMessage::GameFightJoinRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTJOINREQUESTMESSAGE;
}

