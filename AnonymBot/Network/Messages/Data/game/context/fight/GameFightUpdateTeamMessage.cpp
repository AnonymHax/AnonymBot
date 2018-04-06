#include "GameFightUpdateTeamMessage.h"

void GameFightUpdateTeamMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightUpdateTeamMessage(param1);
}

void GameFightUpdateTeamMessage::serializeAs_GameFightUpdateTeamMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightUpdateTeamMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeShort((short)this->fightId);
    this->team->serializeAs_FightTeamInformations(param1);
    return;
  }
}

void GameFightUpdateTeamMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightUpdateTeamMessage(param1);
}

void GameFightUpdateTeamMessage::deserializeAs_GameFightUpdateTeamMessage(Reader *param1)
{
  this->fightId = param1->readShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightUpdateTeamMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightUpdateTeamMessage.fightId.";
  }
  else
  {
    this->team = QSharedPointer<FightTeamInformations>(new FightTeamInformations() );
    this->team->deserialize(param1);
    return;
  }
}

GameFightUpdateTeamMessage::GameFightUpdateTeamMessage()
{
  m_type = MessageEnum::GAMEFIGHTUPDATETEAMMESSAGE;
}

