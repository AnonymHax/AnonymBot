#include "QueueStatusMessage.h"

void QueueStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_QueueStatusMessage(param1);
}

void QueueStatusMessage::serializeAs_QueueStatusMessage(Writer *param1)
{
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element position.";
  }
  else
  {
    param1->writeShort((short)this->position);
    if(this->total < 0 || this->total > 65535)
    {
      qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element total.";
    }
    else
    {
      param1->writeShort((short)this->total);
      return;
    }
  }
}

void QueueStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QueueStatusMessage(param1);
}

void QueueStatusMessage::deserializeAs_QueueStatusMessage(Reader *param1)
{
  this->position = param1->readUShort();
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element of QueueStatusMessage.position.";
  }
  else
  {
    this->total = param1->readUShort();
    if(this->total < 0 || this->total > 65535)
    {
      qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element of QueueStatusMessage.total.";
    }
    else
    {
      return;
    }
  }
}

QueueStatusMessage::QueueStatusMessage()
{
  m_type = MessageEnum::QUEUESTATUSMESSAGE;
}

