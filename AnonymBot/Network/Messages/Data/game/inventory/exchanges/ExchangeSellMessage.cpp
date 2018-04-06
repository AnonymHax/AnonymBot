#include "ExchangeSellMessage.h"

void ExchangeSellMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeSellMessage(param1);
}

void ExchangeSellMessage::serializeAs_ExchangeSellMessage(Writer *param1)
{
  if(this->objectToSellId < 0)
  {
    qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->objectToSellId << ") on element objectToSellId.";
  }
  else
  {
    param1->writeVarInt((int)this->objectToSellId);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ExchangeSellMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeSellMessage(param1);
}

void ExchangeSellMessage::deserializeAs_ExchangeSellMessage(Reader *param1)
{
  this->objectToSellId = param1->readVarUhInt();
  if(this->objectToSellId < 0)
  {
    qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->objectToSellId << ") on element of ExchangeSellMessage.objectToSellId.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeSellMessage.quantity.";
    }
    else
    {
      return;
    }
  }
}

ExchangeSellMessage::ExchangeSellMessage()
{
  m_type = MessageEnum::EXCHANGESELLMESSAGE;
}

