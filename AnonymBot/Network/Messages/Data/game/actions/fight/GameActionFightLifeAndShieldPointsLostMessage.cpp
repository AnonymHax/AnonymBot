#include "GameActionFightLifeAndShieldPointsLostMessage.h"

void GameActionFightLifeAndShieldPointsLostMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightLifeAndShieldPointsLostMessage(param1);
}

void GameActionFightLifeAndShieldPointsLostMessage::serializeAs_GameActionFightLifeAndShieldPointsLostMessage(Writer *param1)
{
  GameActionFightLifePointsLostMessage::serializeAs_GameActionFightLifePointsLostMessage(param1);
  if(this->shieldLoss < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifeAndShieldPointsLostMessage -"<<"Forbidden value (" << this->shieldLoss << ") on element shieldLoss.";
  }
  else
  {
    param1->writeVarShort((int)this->shieldLoss);
    return;
  }
}

void GameActionFightLifeAndShieldPointsLostMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightLifeAndShieldPointsLostMessage(param1);
}

void GameActionFightLifeAndShieldPointsLostMessage::deserializeAs_GameActionFightLifeAndShieldPointsLostMessage(Reader *param1)
{
  GameActionFightLifePointsLostMessage::deserialize(param1);
  this->shieldLoss = param1->readVarUhShort();
  if(this->shieldLoss < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifeAndShieldPointsLostMessage -"<<"Forbidden value (" << this->shieldLoss << ") on element of GameActionFightLifeAndShieldPointsLostMessage.shieldLoss.";
  }
  else
  {
    return;
  }
}

GameActionFightLifeAndShieldPointsLostMessage::GameActionFightLifeAndShieldPointsLostMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE;
}

