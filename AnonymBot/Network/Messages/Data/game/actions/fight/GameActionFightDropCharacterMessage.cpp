#include "GameActionFightDropCharacterMessage.h"

void GameActionFightDropCharacterMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDropCharacterMessage(param1);
}

void GameActionFightDropCharacterMessage::serializeAs_GameActionFightDropCharacterMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeShort((short)this->cellId);
      return;
    }
  }
}

void GameActionFightDropCharacterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDropCharacterMessage(param1);
}

void GameActionFightDropCharacterMessage::deserializeAs_GameActionFightDropCharacterMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDropCharacterMessage.targetId.";
  }
  else
  {
    this->cellId = param1->readShort();
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightDropCharacterMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightDropCharacterMessage::GameActionFightDropCharacterMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDROPCHARACTERMESSAGE;
}

