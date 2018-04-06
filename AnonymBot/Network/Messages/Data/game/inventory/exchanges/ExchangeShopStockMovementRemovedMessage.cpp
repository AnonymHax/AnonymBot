#include "ExchangeShopStockMovementRemovedMessage.h"

void ExchangeShopStockMovementRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeShopStockMovementRemovedMessage(param1);
}

void ExchangeShopStockMovementRemovedMessage::serializeAs_ExchangeShopStockMovementRemovedMessage(Writer *param1)
{
  if(this->objectId < 0)
  {
    qDebug()<<"ERREUR - ExchangeShopStockMovementRemovedMessage -"<<"Forbidden value (" << this->objectId << ") on element objectId.";
  }
  else
  {
    param1->writeVarInt((int)this->objectId);
    return;
  }
}

void ExchangeShopStockMovementRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeShopStockMovementRemovedMessage(param1);
}

void ExchangeShopStockMovementRemovedMessage::deserializeAs_ExchangeShopStockMovementRemovedMessage(Reader *param1)
{
  this->objectId = param1->readVarUhInt();
  if(this->objectId < 0)
  {
    qDebug()<<"ERREUR - ExchangeShopStockMovementRemovedMessage -"<<"Forbidden value (" << this->objectId << ") on element of ExchangeShopStockMovementRemovedMessage.objectId.";
  }
  else
  {
    return;
  }
}

ExchangeShopStockMovementRemovedMessage::ExchangeShopStockMovementRemovedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE;
}

