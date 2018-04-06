#include "GameFightOptionStateUpdateMessage.h"

void GameFightOptionStateUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightOptionStateUpdateMessage(param1);
}

void GameFightOptionStateUpdateMessage::serializeAs_GameFightOptionStateUpdateMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeShort((short)this->fightId);
    param1->writeByte(this->teamId);
    param1->writeByte(this->option);
    param1->writeBool(this->state);
    return;
  }
}

void GameFightOptionStateUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightOptionStateUpdateMessage(param1);
}

void GameFightOptionStateUpdateMessage::deserializeAs_GameFightOptionStateUpdateMessage(Reader *param1)
{
  this->fightId = param1->readShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightOptionStateUpdateMessage.fightId.";
  }
  else
  {
    this->teamId = param1->readByte();
    if(this->teamId < 0)
    {
      qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->teamId << ") on element of GameFightOptionStateUpdateMessage.teamId.";
    }
    else
    {
      this->option = param1->readByte();
      if(this->option < 0)
      {
        qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->option << ") on element of GameFightOptionStateUpdateMessage.option.";
      }
      else
      {
        this->state = param1->readBool();
        return;
      }
    }
  }
}

GameFightOptionStateUpdateMessage::GameFightOptionStateUpdateMessage()
{
  m_type = MessageEnum::GAMEFIGHTOPTIONSTATEUPDATEMESSAGE;
}

