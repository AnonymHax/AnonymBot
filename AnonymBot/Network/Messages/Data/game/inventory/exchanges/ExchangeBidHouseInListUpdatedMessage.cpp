#include "ExchangeBidHouseInListUpdatedMessage.h"

void ExchangeBidHouseInListUpdatedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseInListUpdatedMessage(param1);
}

void ExchangeBidHouseInListUpdatedMessage::serializeAs_ExchangeBidHouseInListUpdatedMessage(Writer *param1)
{
  ExchangeBidHouseInListAddedMessage::serializeAs_ExchangeBidHouseInListAddedMessage(param1);
}

void ExchangeBidHouseInListUpdatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseInListUpdatedMessage(param1);
}

void ExchangeBidHouseInListUpdatedMessage::deserializeAs_ExchangeBidHouseInListUpdatedMessage(Reader *param1)
{
  ExchangeBidHouseInListAddedMessage::deserialize(param1);
}

ExchangeBidHouseInListUpdatedMessage::ExchangeBidHouseInListUpdatedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE;
}

