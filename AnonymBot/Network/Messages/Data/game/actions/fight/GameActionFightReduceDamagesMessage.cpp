#include "GameActionFightReduceDamagesMessage.h"

void GameActionFightReduceDamagesMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightReduceDamagesMessage(param1);
}

void GameActionFightReduceDamagesMessage::serializeAs_GameActionFightReduceDamagesMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->amount < 0)
    {
      qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
    }
    else
    {
      param1->writeVarInt((int)this->amount);
      return;
    }
  }
}

void GameActionFightReduceDamagesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightReduceDamagesMessage(param1);
}

void GameActionFightReduceDamagesMessage::deserializeAs_GameActionFightReduceDamagesMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightReduceDamagesMessage.targetId.";
  }
  else
  {
    this->amount = param1->readVarUhInt();
    if(this->amount < 0)
    {
      qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->amount << ") on element of GameActionFightReduceDamagesMessage.amount.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightReduceDamagesMessage::GameActionFightReduceDamagesMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE;
}

