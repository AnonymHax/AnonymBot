#include "GameActionFightInvisibilityMessage.h"

void GameActionFightInvisibilityMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightInvisibilityMessage(param1);
}

void GameActionFightInvisibilityMessage::serializeAs_GameActionFightInvisibilityMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibilityMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    param1->writeByte(this->state);
    return;
  }
}

void GameActionFightInvisibilityMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightInvisibilityMessage(param1);
}

void GameActionFightInvisibilityMessage::deserializeAs_GameActionFightInvisibilityMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibilityMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightInvisibilityMessage.targetId.";
  }
  else
  {
    this->state = param1->readByte();
    if(this->state < 0)
    {
      qDebug()<<"ERREUR - GameActionFightInvisibilityMessage -"<<"Forbidden value (" << this->state << ") on element of GameActionFightInvisibilityMessage.state.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightInvisibilityMessage::GameActionFightInvisibilityMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTINVISIBILITYMESSAGE;
}

