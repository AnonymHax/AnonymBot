#include "GameActionFightDodgePointLossMessage.h"

void GameActionFightDodgePointLossMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDodgePointLossMessage(param1);
}

void GameActionFightDodgePointLossMessage::serializeAs_GameActionFightDodgePointLossMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->amount < 0)
    {
      qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
    }
    else
    {
      param1->writeVarShort((int)this->amount);
      return;
    }
  }
}

void GameActionFightDodgePointLossMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDodgePointLossMessage(param1);
}

void GameActionFightDodgePointLossMessage::deserializeAs_GameActionFightDodgePointLossMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDodgePointLossMessage.targetId.";
  }
  else
  {
    this->amount = param1->readVarUhShort();
    if(this->amount < 0)
    {
      qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->amount << ") on element of GameActionFightDodgePointLossMessage.amount.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightDodgePointLossMessage::GameActionFightDodgePointLossMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE;
}

