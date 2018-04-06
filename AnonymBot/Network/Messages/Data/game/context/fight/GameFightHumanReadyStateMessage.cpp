#include "GameFightHumanReadyStateMessage.h"

void GameFightHumanReadyStateMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightHumanReadyStateMessage(param1);
}

void GameFightHumanReadyStateMessage::serializeAs_GameFightHumanReadyStateMessage(Writer *param1)
{
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightHumanReadyStateMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  else
  {
    param1->writeVarLong((double)this->characterId);
    param1->writeBool(this->isReady);
    return;
  }
}

void GameFightHumanReadyStateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightHumanReadyStateMessage(param1);
}

void GameFightHumanReadyStateMessage::deserializeAs_GameFightHumanReadyStateMessage(Reader *param1)
{
  this->characterId = param1->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightHumanReadyStateMessage -"<<"Forbidden value (" << this->characterId << ") on element of GameFightHumanReadyStateMessage.characterId.";
  }
  else
  {
    this->isReady = param1->readBool();
    return;
  }
}

GameFightHumanReadyStateMessage::GameFightHumanReadyStateMessage()
{
  m_type = MessageEnum::GAMEFIGHTHUMANREADYSTATEMESSAGE;
}

