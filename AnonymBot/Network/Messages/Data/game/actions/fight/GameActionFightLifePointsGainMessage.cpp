#include "GameActionFightLifePointsGainMessage.h"

void GameActionFightLifePointsGainMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightLifePointsGainMessage(param1);
}

void GameActionFightLifePointsGainMessage::serializeAs_GameActionFightLifePointsGainMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->delta < 0)
    {
      qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->delta << ") on element delta.";
    }
    else
    {
      param1->writeVarInt((int)this->delta);
      return;
    }
  }
}

void GameActionFightLifePointsGainMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightLifePointsGainMessage(param1);
}

void GameActionFightLifePointsGainMessage::deserializeAs_GameActionFightLifePointsGainMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightLifePointsGainMessage.targetId.";
  }
  else
  {
    this->delta = param1->readVarUhInt();
    if(this->delta < 0)
    {
      qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->delta << ") on element of GameActionFightLifePointsGainMessage.delta.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightLifePointsGainMessage::GameActionFightLifePointsGainMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE;
}

