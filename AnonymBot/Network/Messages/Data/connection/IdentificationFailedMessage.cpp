#include "IdentificationFailedMessage.h"

void IdentificationFailedMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationFailedMessage(param1);
}

void IdentificationFailedMessage::serializeAs_IdentificationFailedMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void IdentificationFailedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationFailedMessage(param1);
}

void IdentificationFailedMessage::deserializeAs_IdentificationFailedMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - IdentificationFailedMessage -"<<"Forbidden value (" << this->reason << ") on element of IdentificationFailedMessage.reason.";
  }
  else
  {
    return;
  }
}

IdentificationFailedMessage::IdentificationFailedMessage()
{
  m_type = MessageEnum::IDENTIFICATIONFAILEDMESSAGE;
}

