#include "GameActionFightDispellMessage.h"

void GameActionFightDispellMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDispellMessage(param1);
}

void GameActionFightDispellMessage::serializeAs_GameActionFightDispellMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDispellMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameActionFightDispellMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDispellMessage(param1);
}

void GameActionFightDispellMessage::deserializeAs_GameActionFightDispellMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDispellMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDispellMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameActionFightDispellMessage::GameActionFightDispellMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLMESSAGE;
}

