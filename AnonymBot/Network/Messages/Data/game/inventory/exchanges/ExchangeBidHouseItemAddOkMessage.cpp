#include "ExchangeBidHouseItemAddOkMessage.h"

void ExchangeBidHouseItemAddOkMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseItemAddOkMessage(param1);
}

void ExchangeBidHouseItemAddOkMessage::serializeAs_ExchangeBidHouseItemAddOkMessage(Writer *param1)
{
  this->itemInfo->serializeAs_ObjectItemToSellInBid(param1);
}

void ExchangeBidHouseItemAddOkMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseItemAddOkMessage(param1);
}

void ExchangeBidHouseItemAddOkMessage::deserializeAs_ExchangeBidHouseItemAddOkMessage(Reader *param1)
{
  this->itemInfo = QSharedPointer<ObjectItemToSellInBid>(new ObjectItemToSellInBid() );
  this->itemInfo->deserialize(param1);
}

ExchangeBidHouseItemAddOkMessage::ExchangeBidHouseItemAddOkMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEITEMADDOKMESSAGE;
}

