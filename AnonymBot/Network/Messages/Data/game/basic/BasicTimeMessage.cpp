#include "BasicTimeMessage.h"

void BasicTimeMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicTimeMessage(param1);
}

void BasicTimeMessage::serializeAs_BasicTimeMessage(Writer *param1)
{
  if(this->timestamp < 0 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicTimeMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  else
  {
    param1->writeDouble(this->timestamp);
    param1->writeShort((short)this->timezoneOffset);
    return;
  }
}

void BasicTimeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicTimeMessage(param1);
}

void BasicTimeMessage::deserializeAs_BasicTimeMessage(Reader *param1)
{
  this->timestamp = param1->readDouble();
  if(this->timestamp < 0 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicTimeMessage -"<<"Forbidden value (" << this->timestamp << ") on element of BasicTimeMessage.timestamp.";
  }
  else
  {
    this->timezoneOffset = param1->readShort();
    return;
  }
}

BasicTimeMessage::BasicTimeMessage()
{
  m_type = MessageEnum::BASICTIMEMESSAGE;
}

