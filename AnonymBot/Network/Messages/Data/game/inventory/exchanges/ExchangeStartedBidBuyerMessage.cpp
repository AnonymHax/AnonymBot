#include "ExchangeStartedBidBuyerMessage.h"

void ExchangeStartedBidBuyerMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedBidBuyerMessage(param1);
}

void ExchangeStartedBidBuyerMessage::serializeAs_ExchangeStartedBidBuyerMessage(Writer *param1)
{
  this->buyerDescriptor.serializeAs_SellerBuyerDescriptor(param1);
}

void ExchangeStartedBidBuyerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedBidBuyerMessage(param1);
}

void ExchangeStartedBidBuyerMessage::deserializeAs_ExchangeStartedBidBuyerMessage(Reader *param1)
{
  this->buyerDescriptor = SellerBuyerDescriptor();
  this->buyerDescriptor.deserialize(param1);
}

ExchangeStartedBidBuyerMessage::ExchangeStartedBidBuyerMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDBIDBUYERMESSAGE;
}

