#include "ExchangeRequestMessage.h"

void ExchangeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeRequestMessage(param1);
}

void ExchangeRequestMessage::serializeAs_ExchangeRequestMessage(Writer *param1)
{
  param1->writeByte(this->exchangeType);
}

void ExchangeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeRequestMessage(param1);
}

void ExchangeRequestMessage::deserializeAs_ExchangeRequestMessage(Reader *param1)
{
  this->exchangeType = param1->readByte();
}

ExchangeRequestMessage::ExchangeRequestMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTMESSAGE;
}

