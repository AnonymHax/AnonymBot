#include "ExchangeObjectModifyPricedMessage.h"

void ExchangeObjectModifyPricedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectModifyPricedMessage(param1);
}

void ExchangeObjectModifyPricedMessage::serializeAs_ExchangeObjectModifyPricedMessage(Writer *param1)
{
  ExchangeObjectMovePricedMessage::serializeAs_ExchangeObjectMovePricedMessage(param1);
}

void ExchangeObjectModifyPricedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectModifyPricedMessage(param1);
}

void ExchangeObjectModifyPricedMessage::deserializeAs_ExchangeObjectModifyPricedMessage(Reader *param1)
{
  ExchangeObjectMovePricedMessage::deserialize(param1);
}

ExchangeObjectModifyPricedMessage::ExchangeObjectModifyPricedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMODIFYPRICEDMESSAGE;
}

