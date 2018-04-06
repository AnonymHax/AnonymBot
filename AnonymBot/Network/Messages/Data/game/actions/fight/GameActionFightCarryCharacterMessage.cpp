#include "GameActionFightCarryCharacterMessage.h"

void GameActionFightCarryCharacterMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightCarryCharacterMessage(param1);
}

void GameActionFightCarryCharacterMessage::serializeAs_GameActionFightCarryCharacterMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeShort((short)this->cellId);
      return;
    }
  }
}

void GameActionFightCarryCharacterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightCarryCharacterMessage(param1);
}

void GameActionFightCarryCharacterMessage::deserializeAs_GameActionFightCarryCharacterMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightCarryCharacterMessage.targetId.";
  }
  else
  {
    this->cellId = param1->readShort();
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightCarryCharacterMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightCarryCharacterMessage::GameActionFightCarryCharacterMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCARRYCHARACTERMESSAGE;
}

