#include "GameFightNewWaveMessage.h"

void GameFightNewWaveMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightNewWaveMessage(param1);
}

void GameFightNewWaveMessage::serializeAs_GameFightNewWaveMessage(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameFightNewWaveMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeByte(this->id);
    param1->writeByte(this->teamId);
    param1->writeShort((short)this->nbTurnBeforeNextWave);
    return;
  }
}

void GameFightNewWaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightNewWaveMessage(param1);
}

void GameFightNewWaveMessage::deserializeAs_GameFightNewWaveMessage(Reader *param1)
{
  this->id = param1->readByte();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameFightNewWaveMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightNewWaveMessage.id.";
  }
  else
  {
    this->teamId = param1->readByte();
    if(this->teamId < 0)
    {
      qDebug()<<"ERREUR - GameFightNewWaveMessage -"<<"Forbidden value (" << this->teamId << ") on element of GameFightNewWaveMessage.teamId.";
    }
    else
    {
      this->nbTurnBeforeNextWave = param1->readShort();
      return;
    }
  }
}

GameFightNewWaveMessage::GameFightNewWaveMessage()
{
  m_type = MessageEnum::GAMEFIGHTNEWWAVEMESSAGE;
}

