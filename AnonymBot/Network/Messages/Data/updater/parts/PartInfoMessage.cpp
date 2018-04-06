#include "PartInfoMessage.h"

void PartInfoMessage::serialize(Writer *param1)
{
  this->serializeAs_PartInfoMessage(param1);
}

void PartInfoMessage::serializeAs_PartInfoMessage(Writer *param1)
{
  this->part.serializeAs_ContentPart(param1);
  param1->writeFloat(this->installationPercent);
}

void PartInfoMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartInfoMessage(param1);
}

void PartInfoMessage::deserializeAs_PartInfoMessage(Reader *param1)
{
  this->part = ContentPart();
  this->part.deserialize(param1);
  this->installationPercent = param1->readFloat();
}

PartInfoMessage::PartInfoMessage()
{
  m_type = MessageEnum::PARTINFOMESSAGE;
}

