#include "GuestLimitationMessage.h"

void GuestLimitationMessage::serialize(Writer *param1)
{
  this->serializeAs_GuestLimitationMessage(param1);
}

void GuestLimitationMessage::serializeAs_GuestLimitationMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void GuestLimitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuestLimitationMessage(param1);
}

void GuestLimitationMessage::deserializeAs_GuestLimitationMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - GuestLimitationMessage -"<<"Forbidden value (" << this->reason << ") on element of GuestLimitationMessage.reason.";
  }
  else
  {
    return;
  }
}

GuestLimitationMessage::GuestLimitationMessage()
{
  m_type = MessageEnum::GUESTLIMITATIONMESSAGE;
}

