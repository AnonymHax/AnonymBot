#include "ExchangeMountsStableBornAddMessage.h"

void ExchangeMountsStableBornAddMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMountsStableBornAddMessage(param1);
}

void ExchangeMountsStableBornAddMessage::serializeAs_ExchangeMountsStableBornAddMessage(Writer *param1)
{
  ExchangeMountsStableAddMessage::serializeAs_ExchangeMountsStableAddMessage(param1);
}

void ExchangeMountsStableBornAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMountsStableBornAddMessage(param1);
}

void ExchangeMountsStableBornAddMessage::deserializeAs_ExchangeMountsStableBornAddMessage(Reader *param1)
{
  ExchangeMountsStableAddMessage::deserialize(param1);
}

ExchangeMountsStableBornAddMessage::ExchangeMountsStableBornAddMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSSTABLEBORNADDMESSAGE;
}

