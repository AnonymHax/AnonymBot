#include "ExchangeObjectMessage.h"

void ExchangeObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectMessage(param1);
}

void ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(Writer *param1)
{
  param1->writeBool(this->remote);
}

void ExchangeObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectMessage(param1);
}

void ExchangeObjectMessage::deserializeAs_ExchangeObjectMessage(Reader *param1)
{
  this->remote = param1->readBool();
}

ExchangeObjectMessage::ExchangeObjectMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMESSAGE;
}

