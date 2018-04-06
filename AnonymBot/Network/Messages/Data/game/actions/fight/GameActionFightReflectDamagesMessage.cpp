#include "GameActionFightReflectDamagesMessage.h"

void GameActionFightReflectDamagesMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightReflectDamagesMessage(param1);
}

void GameActionFightReflectDamagesMessage::serializeAs_GameActionFightReflectDamagesMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightReflectDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameActionFightReflectDamagesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightReflectDamagesMessage(param1);
}

void GameActionFightReflectDamagesMessage::deserializeAs_GameActionFightReflectDamagesMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightReflectDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightReflectDamagesMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameActionFightReflectDamagesMessage::GameActionFightReflectDamagesMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE;
}

