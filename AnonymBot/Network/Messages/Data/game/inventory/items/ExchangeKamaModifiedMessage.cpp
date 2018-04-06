#include "ExchangeKamaModifiedMessage.h"

void ExchangeKamaModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeKamaModifiedMessage(param1);
}

void ExchangeKamaModifiedMessage::serializeAs_ExchangeKamaModifiedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeKamaModifiedMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  else
  {
    param1->writeVarInt((int)this->quantity);
    return;
  }
}

void ExchangeKamaModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeKamaModifiedMessage(param1);
}

void ExchangeKamaModifiedMessage::deserializeAs_ExchangeKamaModifiedMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->quantity = param1->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeKamaModifiedMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeKamaModifiedMessage.quantity.";
  }
  else
  {
    return;
  }
}

ExchangeKamaModifiedMessage::ExchangeKamaModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE;
}

