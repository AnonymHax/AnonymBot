#include "LoginQueueStatusMessage.h"

void LoginQueueStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_LoginQueueStatusMessage(param1);
}

void LoginQueueStatusMessage::serializeAs_LoginQueueStatusMessage(Writer *param1)
{
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element position.";
  }
  else
  {
    param1->writeShort((short)this->position);
    if(this->total < 0 || this->total > 65535)
    {
      qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element total.";
    }
    else
    {
      param1->writeShort((short)this->total);
      return;
    }
  }
}

void LoginQueueStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LoginQueueStatusMessage(param1);
}

void LoginQueueStatusMessage::deserializeAs_LoginQueueStatusMessage(Reader *param1)
{
  this->position = param1->readUShort();
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element of LoginQueueStatusMessage.position.";
  }
  else
  {
    this->total = param1->readUShort();
    if(this->total < 0 || this->total > 65535)
    {
      qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element of LoginQueueStatusMessage.total.";
    }
    else
    {
      return;
    }
  }
}

LoginQueueStatusMessage::LoginQueueStatusMessage()
{
  m_type = MessageEnum::LOGINQUEUESTATUSMESSAGE;
}

