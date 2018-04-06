#include "AccountLoggingKickedMessage.h"

void AccountLoggingKickedMessage::serialize(Writer *param1)
{
  this->serializeAs_AccountLoggingKickedMessage(param1);
}

void AccountLoggingKickedMessage::serializeAs_AccountLoggingKickedMessage(Writer *param1)
{
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->days << ") on element days.";
  }
  else
  {
    param1->writeVarShort((int)this->days);
    if(this->hours < 0)
    {
      qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->hours << ") on element hours.";
    }
    else
    {
      param1->writeByte(this->hours);
      if(this->minutes < 0)
      {
        qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->minutes << ") on element minutes.";
      }
      else
      {
        param1->writeByte(this->minutes);
        return;
      }
    }
  }
}

void AccountLoggingKickedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AccountLoggingKickedMessage(param1);
}

void AccountLoggingKickedMessage::deserializeAs_AccountLoggingKickedMessage(Reader *param1)
{
  this->days = param1->readVarUhShort();
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->days << ") on element of AccountLoggingKickedMessage.days.";
  }
  else
  {
    this->hours = param1->readByte();
    if(this->hours < 0)
    {
      qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->hours << ") on element of AccountLoggingKickedMessage.hours.";
    }
    else
    {
      this->minutes = param1->readByte();
      if(this->minutes < 0)
      {
        qDebug()<<"ERREUR - AccountLoggingKickedMessage -"<<"Forbidden value (" << this->minutes << ") on element of AccountLoggingKickedMessage.minutes.";
      }
      else
      {
        return;
      }
    }
  }
}

AccountLoggingKickedMessage::AccountLoggingKickedMessage()
{
  m_type = MessageEnum::ACCOUNTLOGGINGKICKEDMESSAGE;
}

