#include "AbstractGameActionMessage.h"

void AbstractGameActionMessage::serialize(Writer *param1)
{
  this->serializeAs_AbstractGameActionMessage(param1);
}

void AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(Writer *param1)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  else
  {
    param1->writeVarShort((int)this->actionId);
    if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
    }
    else
    {
      param1->writeDouble(this->sourceId);
      return;
    }
  }
}

void AbstractGameActionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractGameActionMessage(param1);
}

void AbstractGameActionMessage::deserializeAs_AbstractGameActionMessage(Reader *param1)
{
  this->actionId = param1->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->actionId << ") on element of AbstractGameActionMessage.actionId.";
  }
  else
  {
    this->sourceId = param1->readDouble();
    if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->sourceId << ") on element of AbstractGameActionMessage.sourceId.";
    }
    else
    {
      return;
    }
  }
}

AbstractGameActionMessage::AbstractGameActionMessage()
{
  m_type = MessageEnum::ABSTRACTGAMEACTIONMESSAGE;
}

