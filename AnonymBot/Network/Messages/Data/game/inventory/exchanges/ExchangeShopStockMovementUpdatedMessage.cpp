#include "ExchangeShopStockMovementUpdatedMessage.h"

void ExchangeShopStockMovementUpdatedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeShopStockMovementUpdatedMessage(param1);
}

void ExchangeShopStockMovementUpdatedMessage::serializeAs_ExchangeShopStockMovementUpdatedMessage(Writer *param1)
{
  this->objectInfo->serializeAs_ObjectItemToSell(param1);
}

void ExchangeShopStockMovementUpdatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeShopStockMovementUpdatedMessage(param1);
}

void ExchangeShopStockMovementUpdatedMessage::deserializeAs_ExchangeShopStockMovementUpdatedMessage(Reader *param1)
{
  this->objectInfo = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
  this->objectInfo->deserialize(param1);
}

ExchangeShopStockMovementUpdatedMessage::ExchangeShopStockMovementUpdatedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE;
}

