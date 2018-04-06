#include "ExchangeRequestedMessage.h"

void ExchangeRequestedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeRequestedMessage(param1);
}

void ExchangeRequestedMessage::serializeAs_ExchangeRequestedMessage(Writer *param1)
{
  param1->writeByte(this->exchangeType);
}

void ExchangeRequestedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeRequestedMessage(param1);
}

void ExchangeRequestedMessage::deserializeAs_ExchangeRequestedMessage(Reader *param1)
{
  this->exchangeType = param1->readByte();
}

ExchangeRequestedMessage::ExchangeRequestedMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTEDMESSAGE;
}

