#include "GameActionFightSlideMessage.h"

void GameActionFightSlideMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightSlideMessage(param1);
}

void GameActionFightSlideMessage::serializeAs_GameActionFightSlideMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->startCellId < -1 || this->startCellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->startCellId << ") on element startCellId.";
    }
    else
    {
      param1->writeShort((short)this->startCellId);
      if(this->endCellId < -1 || this->endCellId > 559)
      {
        qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->endCellId << ") on element endCellId.";
      }
      else
      {
        param1->writeShort((short)this->endCellId);
        return;
      }
    }
  }
}

void GameActionFightSlideMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightSlideMessage(param1);
}

void GameActionFightSlideMessage::deserializeAs_GameActionFightSlideMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightSlideMessage.targetId.";
  }
  else
  {
    this->startCellId = param1->readShort();
    if(this->startCellId < -1 || this->startCellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->startCellId << ") on element of GameActionFightSlideMessage.startCellId.";
    }
    else
    {
      this->endCellId = param1->readShort();
      if(this->endCellId < -1 || this->endCellId > 559)
      {
        qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->endCellId << ") on element of GameActionFightSlideMessage.endCellId.";
      }
      else
      {
        return;
      }
    }
  }
}

GameActionFightSlideMessage::GameActionFightSlideMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSLIDEMESSAGE;
}

