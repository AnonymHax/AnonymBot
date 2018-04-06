#include "GameActionFightStealKamaMessage.h"

void GameActionFightStealKamaMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightStealKamaMessage(param1);
}

void GameActionFightStealKamaMessage::serializeAs_GameActionFightStealKamaMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->amount < 0)
    {
      qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
    }
    else
    {
      param1->writeVarInt((int)this->amount);
      return;
    }
  }
}

void GameActionFightStealKamaMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightStealKamaMessage(param1);
}

void GameActionFightStealKamaMessage::deserializeAs_GameActionFightStealKamaMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightStealKamaMessage.targetId.";
  }
  else
  {
    this->amount = param1->readVarUhInt();
    if(this->amount < 0)
    {
      qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->amount << ") on element of GameActionFightStealKamaMessage.amount.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightStealKamaMessage::GameActionFightStealKamaMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSTEALKAMAMESSAGE;
}

