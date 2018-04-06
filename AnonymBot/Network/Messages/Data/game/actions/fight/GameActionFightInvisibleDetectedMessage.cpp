#include "GameActionFightInvisibleDetectedMessage.h"

void GameActionFightInvisibleDetectedMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightInvisibleDetectedMessage(param1);
}

void GameActionFightInvisibleDetectedMessage::serializeAs_GameActionFightInvisibleDetectedMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeShort((short)this->cellId);
      return;
    }
  }
}

void GameActionFightInvisibleDetectedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightInvisibleDetectedMessage(param1);
}

void GameActionFightInvisibleDetectedMessage::deserializeAs_GameActionFightInvisibleDetectedMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightInvisibleDetectedMessage.targetId.";
  }
  else
  {
    this->cellId = param1->readShort();
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightInvisibleDetectedMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightInvisibleDetectedMessage::GameActionFightInvisibleDetectedMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE;
}

