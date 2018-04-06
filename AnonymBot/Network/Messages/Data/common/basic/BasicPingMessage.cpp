#include "BasicPingMessage.h"

void BasicPingMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicPingMessage(param1);
}

void BasicPingMessage::serializeAs_BasicPingMessage(Writer *param1)
{
  param1->writeBool(this->quiet);
}

void BasicPingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicPingMessage(param1);
}

void BasicPingMessage::deserializeAs_BasicPingMessage(Reader *param1)
{
  this->quiet = param1->readBool();
}

BasicPingMessage::BasicPingMessage()
{
  m_type = MessageEnum::BASICPINGMESSAGE;
}

