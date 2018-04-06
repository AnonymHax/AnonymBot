#include "GameActionFightExchangePositionsMessage.h"

void GameActionFightExchangePositionsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightExchangePositionsMessage(param1);
}

void GameActionFightExchangePositionsMessage::serializeAs_GameActionFightExchangePositionsMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->casterCellId < -1 || this->casterCellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->casterCellId << ") on element casterCellId.";
    }
    else
    {
      param1->writeShort((short)this->casterCellId);
      if(this->targetCellId < -1 || this->targetCellId > 559)
      {
        qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetCellId << ") on element targetCellId.";
      }
      else
      {
        param1->writeShort((short)this->targetCellId);
        return;
      }
    }
  }
}

void GameActionFightExchangePositionsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightExchangePositionsMessage(param1);
}

void GameActionFightExchangePositionsMessage::deserializeAs_GameActionFightExchangePositionsMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightExchangePositionsMessage.targetId.";
  }
  else
  {
    this->casterCellId = param1->readShort();
    if(this->casterCellId < -1 || this->casterCellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->casterCellId << ") on element of GameActionFightExchangePositionsMessage.casterCellId.";
    }
    else
    {
      this->targetCellId = param1->readShort();
      if(this->targetCellId < -1 || this->targetCellId > 559)
      {
        qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetCellId << ") on element of GameActionFightExchangePositionsMessage.targetCellId.";
      }
      else
      {
        return;
      }
    }
  }
}

GameActionFightExchangePositionsMessage::GameActionFightExchangePositionsMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE;
}

