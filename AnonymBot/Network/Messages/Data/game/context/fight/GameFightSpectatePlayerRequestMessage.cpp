#include "GameFightSpectatePlayerRequestMessage.h"

void GameFightSpectatePlayerRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightSpectatePlayerRequestMessage(param1);
}

void GameFightSpectatePlayerRequestMessage::serializeAs_GameFightSpectatePlayerRequestMessage(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightSpectatePlayerRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void GameFightSpectatePlayerRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightSpectatePlayerRequestMessage(param1);
}

void GameFightSpectatePlayerRequestMessage::deserializeAs_GameFightSpectatePlayerRequestMessage(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightSpectatePlayerRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of GameFightSpectatePlayerRequestMessage.playerId.";
  }
  else
  {
    return;
  }
}

GameFightSpectatePlayerRequestMessage::GameFightSpectatePlayerRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE;
}

