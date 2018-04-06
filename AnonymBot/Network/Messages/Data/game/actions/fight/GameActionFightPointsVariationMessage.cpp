#include "GameActionFightPointsVariationMessage.h"

void GameActionFightPointsVariationMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightPointsVariationMessage(param1);
}

void GameActionFightPointsVariationMessage::serializeAs_GameActionFightPointsVariationMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightPointsVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    param1->writeShort((short)this->delta);
    return;
  }
}

void GameActionFightPointsVariationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightPointsVariationMessage(param1);
}

void GameActionFightPointsVariationMessage::deserializeAs_GameActionFightPointsVariationMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightPointsVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightPointsVariationMessage.targetId.";
  }
  else
  {
    this->delta = param1->readShort();
    return;
  }
}

GameActionFightPointsVariationMessage::GameActionFightPointsVariationMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE;
}

