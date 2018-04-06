#include "GameFightStartingMessage.h"

void GameFightStartingMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightStartingMessage(param1);
}

void GameFightStartingMessage::serializeAs_GameFightStartingMessage(Writer *param1)
{
  param1->writeByte(this->fightType);
  if(this->attackerId < -9.007199254740992E15 || this->attackerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->attackerId << ") on element attackerId.";
  }
  else
  {
    param1->writeDouble(this->attackerId);
    if(this->defenderId < -9.007199254740992E15 || this->defenderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->defenderId << ") on element defenderId.";
    }
    else
    {
      param1->writeDouble(this->defenderId);
      return;
    }
  }
}

void GameFightStartingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightStartingMessage(param1);
}

void GameFightStartingMessage::deserializeAs_GameFightStartingMessage(Reader *param1)
{
  this->fightType = param1->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->fightType << ") on element of GameFightStartingMessage.fightType.";
  }
  else
  {
    this->attackerId = param1->readDouble();
    if(this->attackerId < -9.007199254740992E15 || this->attackerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->attackerId << ") on element of GameFightStartingMessage.attackerId.";
    }
    else
    {
      this->defenderId = param1->readDouble();
      if(this->defenderId < -9.007199254740992E15 || this->defenderId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->defenderId << ") on element of GameFightStartingMessage.defenderId.";
      }
      else
      {
        return;
      }
    }
  }
}

GameFightStartingMessage::GameFightStartingMessage()
{
  m_type = MessageEnum::GAMEFIGHTSTARTINGMESSAGE;
}

