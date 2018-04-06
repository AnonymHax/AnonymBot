#include "IdentificationAccountForceMessage.h"

void IdentificationAccountForceMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationAccountForceMessage(param1);
}

void IdentificationAccountForceMessage::serializeAs_IdentificationAccountForceMessage(Writer *param1)
{
  IdentificationMessage::serializeAs_IdentificationMessage(param1);
  param1->writeUTF(this->forcedAccountLogin);
}

void IdentificationAccountForceMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationAccountForceMessage(param1);
}

void IdentificationAccountForceMessage::deserializeAs_IdentificationAccountForceMessage(Reader *param1)
{
  IdentificationMessage::deserialize(param1);
  this->forcedAccountLogin = param1->readUTF();
}

IdentificationAccountForceMessage::IdentificationAccountForceMessage()
{
  m_type = MessageEnum::IDENTIFICATIONACCOUNTFORCEMESSAGE;
}

