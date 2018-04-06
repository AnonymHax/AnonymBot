#include "BasicDateMessage.h"

void BasicDateMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicDateMessage(param1);
}

void BasicDateMessage::serializeAs_BasicDateMessage(Writer *param1)
{
  if(this->day < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->day << ") on element day.";
  }
  else
  {
    param1->writeByte(this->day);
    if(this->month < 0)
    {
      qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->month << ") on element month.";
    }
    else
    {
      param1->writeByte(this->month);
      if(this->year < 0)
      {
        qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->year << ") on element year.";
      }
      else
      {
        param1->writeShort((short)this->year);
        return;
      }
    }
  }
}

void BasicDateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicDateMessage(param1);
}

void BasicDateMessage::deserializeAs_BasicDateMessage(Reader *param1)
{
  this->day = param1->readByte();
  if(this->day < 0)
  {
    qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->day << ") on element of BasicDateMessage.day.";
  }
  else
  {
    this->month = param1->readByte();
    if(this->month < 0)
    {
      qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->month << ") on element of BasicDateMessage.month.";
    }
    else
    {
      this->year = param1->readShort();
      if(this->year < 0)
      {
        qDebug()<<"ERREUR - BasicDateMessage -"<<"Forbidden value (" << this->year << ") on element of BasicDateMessage.year.";
      }
      else
      {
        return;
      }
    }
  }
}

BasicDateMessage::BasicDateMessage()
{
  m_type = MessageEnum::BASICDATEMESSAGE;
}

