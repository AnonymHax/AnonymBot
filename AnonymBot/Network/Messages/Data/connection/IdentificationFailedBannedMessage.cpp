#include "IdentificationFailedBannedMessage.h"

void IdentificationFailedBannedMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationFailedBannedMessage(param1);
}

void IdentificationFailedBannedMessage::serializeAs_IdentificationFailedBannedMessage(Writer *param1)
{
  IdentificationFailedMessage::serializeAs_IdentificationFailedMessage(param1);
  if(this->banEndDate < 0 || this->banEndDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationFailedBannedMessage -"<<"Forbidden value (" << this->banEndDate << ") on element banEndDate.";
  }
  else
  {
    param1->writeDouble(this->banEndDate);
    return;
  }
}

void IdentificationFailedBannedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationFailedBannedMessage(param1);
}

void IdentificationFailedBannedMessage::deserializeAs_IdentificationFailedBannedMessage(Reader *param1)
{
  IdentificationFailedMessage::deserialize(param1);
  this->banEndDate = param1->readDouble();
  if(this->banEndDate < 0 || this->banEndDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationFailedBannedMessage -"<<"Forbidden value (" << this->banEndDate << ") on element of IdentificationFailedBannedMessage.banEndDate.";
  }
  else
  {
    return;
  }
}

IdentificationFailedBannedMessage::IdentificationFailedBannedMessage()
{
  m_type = MessageEnum::IDENTIFICATIONFAILEDBANNEDMESSAGE;
}

