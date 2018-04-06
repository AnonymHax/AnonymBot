#include "ExchangeBidHouseItemRemoveOkMessage.h"

void ExchangeBidHouseItemRemoveOkMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseItemRemoveOkMessage(param1);
}

void ExchangeBidHouseItemRemoveOkMessage::serializeAs_ExchangeBidHouseItemRemoveOkMessage(Writer *param1)
{
  param1->writeInt((int)this->sellerId);
}

void ExchangeBidHouseItemRemoveOkMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseItemRemoveOkMessage(param1);
}

void ExchangeBidHouseItemRemoveOkMessage::deserializeAs_ExchangeBidHouseItemRemoveOkMessage(Reader *param1)
{
  this->sellerId = param1->readInt();
}

ExchangeBidHouseItemRemoveOkMessage::ExchangeBidHouseItemRemoveOkMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE;
}

