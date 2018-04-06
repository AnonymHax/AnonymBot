#include "ExchangeStartedMessage.h"

void ExchangeStartedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedMessage(param1);
}

void ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(Writer *param1)
{
  param1->writeByte(this->exchangeType);
}

void ExchangeStartedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedMessage(param1);
}

void ExchangeStartedMessage::deserializeAs_ExchangeStartedMessage(Reader *param1)
{
  this->exchangeType = param1->readByte();
}

ExchangeStartedMessage::ExchangeStartedMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDMESSAGE;
}

