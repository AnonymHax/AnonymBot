#include "GameActionFightThrowCharacterMessage.h"

void GameActionFightThrowCharacterMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightThrowCharacterMessage(param1);
}

void GameActionFightThrowCharacterMessage::serializeAs_GameActionFightThrowCharacterMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeShort((short)this->cellId);
      return;
    }
  }
}

void GameActionFightThrowCharacterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightThrowCharacterMessage(param1);
}

void GameActionFightThrowCharacterMessage::deserializeAs_GameActionFightThrowCharacterMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightThrowCharacterMessage.targetId.";
  }
  else
  {
    this->cellId = param1->readShort();
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightThrowCharacterMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightThrowCharacterMessage::GameActionFightThrowCharacterMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTHROWCHARACTERMESSAGE;
}

