#include "GameActionFightChangeLookMessage.h"

void GameActionFightChangeLookMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightChangeLookMessage(param1);
}

void GameActionFightChangeLookMessage::serializeAs_GameActionFightChangeLookMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightChangeLookMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    this->entityLook->serializeAs_EntityLook(param1);
    return;
  }
}

void GameActionFightChangeLookMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightChangeLookMessage(param1);
}

void GameActionFightChangeLookMessage::deserializeAs_GameActionFightChangeLookMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightChangeLookMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightChangeLookMessage.targetId.";
  }
  else
  {
    this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
    this->entityLook->deserialize(param1);
    return;
  }
}

GameActionFightChangeLookMessage::GameActionFightChangeLookMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCHANGELOOKMESSAGE;
}

