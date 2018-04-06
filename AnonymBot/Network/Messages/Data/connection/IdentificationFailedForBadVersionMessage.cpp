#include "IdentificationFailedForBadVersionMessage.h"

void IdentificationFailedForBadVersionMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationFailedForBadVersionMessage(param1);
}

void IdentificationFailedForBadVersionMessage::serializeAs_IdentificationFailedForBadVersionMessage(Writer *param1)
{
  IdentificationFailedMessage::serializeAs_IdentificationFailedMessage(param1);
  this->requiredVersion.serializeAs_Version(param1);
}

void IdentificationFailedForBadVersionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationFailedForBadVersionMessage(param1);
}

void IdentificationFailedForBadVersionMessage::deserializeAs_IdentificationFailedForBadVersionMessage(Reader *param1)
{
  IdentificationFailedMessage::deserialize(param1);
  this->requiredVersion = Version();
  this->requiredVersion.deserialize(param1);
}

IdentificationFailedForBadVersionMessage::IdentificationFailedForBadVersionMessage()
{
  m_type = MessageEnum::IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE;
}

