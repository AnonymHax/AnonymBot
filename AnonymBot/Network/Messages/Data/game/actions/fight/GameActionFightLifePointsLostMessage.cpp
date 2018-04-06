#include "GameActionFightLifePointsLostMessage.h"

void GameActionFightLifePointsLostMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightLifePointsLostMessage(param1);
}

void GameActionFightLifePointsLostMessage::serializeAs_GameActionFightLifePointsLostMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->loss < 0)
    {
      qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->loss << ") on element loss.";
    }
    else
    {
      param1->writeVarInt((int)this->loss);
      if(this->permanentDamages < 0)
      {
        qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->permanentDamages << ") on element permanentDamages.";
      }
      else
      {
        param1->writeVarInt((int)this->permanentDamages);
        return;
      }
    }
  }
}

void GameActionFightLifePointsLostMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightLifePointsLostMessage(param1);
}

void GameActionFightLifePointsLostMessage::deserializeAs_GameActionFightLifePointsLostMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightLifePointsLostMessage.targetId.";
  }
  else
  {
    this->loss = param1->readVarUhInt();
    if(this->loss < 0)
    {
      qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->loss << ") on element of GameActionFightLifePointsLostMessage.loss.";
    }
    else
    {
      this->permanentDamages = param1->readVarUhInt();
      if(this->permanentDamages < 0)
      {
        qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->permanentDamages << ") on element of GameActionFightLifePointsLostMessage.permanentDamages.";
      }
      else
      {
        return;
      }
    }
  }
}

GameActionFightLifePointsLostMessage::GameActionFightLifePointsLostMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE;
}

