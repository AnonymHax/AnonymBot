#include "MailStatusMessage.h"

void MailStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_MailStatusMessage(param1);
}

void MailStatusMessage::serializeAs_MailStatusMessage(Writer *param1)
{
  if(this->unread < 0)
  {
    qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->unread << ") on element unread.";
  }
  else
  {
    param1->writeVarShort((int)this->unread);
    if(this->total < 0)
    {
      qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->total << ") on element total.";
    }
    else
    {
      param1->writeVarShort((int)this->total);
      return;
    }
  }
}

void MailStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MailStatusMessage(param1);
}

void MailStatusMessage::deserializeAs_MailStatusMessage(Reader *param1)
{
  this->unread = param1->readVarUhShort();
  if(this->unread < 0)
  {
    qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->unread << ") on element of MailStatusMessage.unread.";
  }
  else
  {
    this->total = param1->readVarUhShort();
    if(this->total < 0)
    {
      qDebug()<<"ERREUR - MailStatusMessage -"<<"Forbidden value (" << this->total << ") on element of MailStatusMessage.total.";
    }
    else
    {
      return;
    }
  }
}

MailStatusMessage::MailStatusMessage()
{
  m_type = MessageEnum::MAILSTATUSMESSAGE;
}

