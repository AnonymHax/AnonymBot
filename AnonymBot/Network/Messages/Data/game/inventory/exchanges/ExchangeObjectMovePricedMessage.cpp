#include "ExchangeObjectMovePricedMessage.h"

void ExchangeObjectMovePricedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectMovePricedMessage(param1);
}

void ExchangeObjectMovePricedMessage::serializeAs_ExchangeObjectMovePricedMessage(Writer *param1)
{
  ExchangeObjectMoveMessage::serializeAs_ExchangeObjectMoveMessage(param1);
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMovePricedMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  else
  {
    param1->writeVarInt((int)this->price);
    return;
  }
}

void ExchangeObjectMovePricedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectMovePricedMessage(param1);
}

void ExchangeObjectMovePricedMessage::deserializeAs_ExchangeObjectMovePricedMessage(Reader *param1)
{
  ExchangeObjectMoveMessage::deserialize(param1);
  this->price = param1->readVarUhInt();
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMovePricedMessage -"<<"Forbidden value (" << this->price << ") on element of ExchangeObjectMovePricedMessage.price.";
  }
  else
  {
    return;
  }
}

ExchangeObjectMovePricedMessage::ExchangeObjectMovePricedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVEPRICEDMESSAGE;
}

