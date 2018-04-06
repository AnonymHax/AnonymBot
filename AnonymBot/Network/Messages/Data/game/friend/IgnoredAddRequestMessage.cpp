#include "IgnoredAddRequestMessage.h"

void IgnoredAddRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_IgnoredAddRequestMessage(param1);
}

void IgnoredAddRequestMessage::serializeAs_IgnoredAddRequestMessage(Writer *param1)
{
  param1->writeUTF(this->name);
  param1->writeBool(this->session);
}

void IgnoredAddRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredAddRequestMessage(param1);
}

void IgnoredAddRequestMessage::deserializeAs_IgnoredAddRequestMessage(Reader *param1)
{
  this->name = param1->readUTF();
  this->session = param1->readBool();
}

IgnoredAddRequestMessage::IgnoredAddRequestMessage()
{
  m_type = MessageEnum::IGNOREDADDREQUESTMESSAGE;
}

