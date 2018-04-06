#include "ExchangeBidHouseInListRemovedMessage.h"

void ExchangeBidHouseInListRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseInListRemovedMessage(param1);
}

void ExchangeBidHouseInListRemovedMessage::serializeAs_ExchangeBidHouseInListRemovedMessage(Writer *param1)
{
  param1->writeInt((int)this->itemUID);
}

void ExchangeBidHouseInListRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseInListRemovedMessage(param1);
}

void ExchangeBidHouseInListRemovedMessage::deserializeAs_ExchangeBidHouseInListRemovedMessage(Reader *param1)
{
  this->itemUID = param1->readInt();
}

ExchangeBidHouseInListRemovedMessage::ExchangeBidHouseInListRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE;
}

