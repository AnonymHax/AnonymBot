#include "ExchangeRequestOnTaxCollectorMessage.h"

void ExchangeRequestOnTaxCollectorMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeRequestOnTaxCollectorMessage(param1);
}

void ExchangeRequestOnTaxCollectorMessage::serializeAs_ExchangeRequestOnTaxCollectorMessage(Writer *param1)
{
  param1->writeInt((int)this->taxCollectorId);
}

void ExchangeRequestOnTaxCollectorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeRequestOnTaxCollectorMessage(param1);
}

void ExchangeRequestOnTaxCollectorMessage::deserializeAs_ExchangeRequestOnTaxCollectorMessage(Reader *param1)
{
  this->taxCollectorId = param1->readInt();
}

ExchangeRequestOnTaxCollectorMessage::ExchangeRequestOnTaxCollectorMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTONTAXCOLLECTORMESSAGE;
}

