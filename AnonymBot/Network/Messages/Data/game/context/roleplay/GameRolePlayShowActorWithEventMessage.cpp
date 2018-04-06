#include "GameRolePlayShowActorWithEventMessage.h"

void GameRolePlayShowActorWithEventMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayShowActorWithEventMessage(param1);
}

void GameRolePlayShowActorWithEventMessage::serializeAs_GameRolePlayShowActorWithEventMessage(Writer *param1)
{
  GameRolePlayShowActorMessage::serializeAs_GameRolePlayShowActorMessage(param1);
  if(this->actorEventId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayShowActorWithEventMessage -"<<"Forbidden value (" << this->actorEventId << ") on element actorEventId.";
  }
  else
  {
    param1->writeByte(this->actorEventId);
    return;
  }
}

void GameRolePlayShowActorWithEventMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayShowActorWithEventMessage(param1);
}

void GameRolePlayShowActorWithEventMessage::deserializeAs_GameRolePlayShowActorWithEventMessage(Reader *param1)
{
  GameRolePlayShowActorMessage::deserialize(param1);
  this->actorEventId = param1->readByte();
  if(this->actorEventId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayShowActorWithEventMessage -"<<"Forbidden value (" << this->actorEventId << ") on element of GameRolePlayShowActorWithEventMessage.actorEventId.";
  }
  else
  {
    return;
  }
}

GameRolePlayShowActorWithEventMessage::GameRolePlayShowActorWithEventMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE;
}

