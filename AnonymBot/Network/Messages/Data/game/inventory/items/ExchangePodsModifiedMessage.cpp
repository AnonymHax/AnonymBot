#include "ExchangePodsModifiedMessage.h"

void ExchangePodsModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangePodsModifiedMessage(param1);
}

void ExchangePodsModifiedMessage::serializeAs_ExchangePodsModifiedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->currentWeight << ") on element currentWeight.";
  }
  else
  {
    param1->writeVarInt((int)this->currentWeight);
    if(this->maxWeight < 0)
    {
      qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->maxWeight << ") on element maxWeight.";
    }
    else
    {
      param1->writeVarInt((int)this->maxWeight);
      return;
    }
  }
}

void ExchangePodsModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangePodsModifiedMessage(param1);
}

void ExchangePodsModifiedMessage::deserializeAs_ExchangePodsModifiedMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->currentWeight = param1->readVarUhInt();
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->currentWeight << ") on element of ExchangePodsModifiedMessage.currentWeight.";
  }
  else
  {
    this->maxWeight = param1->readVarUhInt();
    if(this->maxWeight < 0)
    {
      qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->maxWeight << ") on element of ExchangePodsModifiedMessage.maxWeight.";
    }
    else
    {
      return;
    }
  }
}

ExchangePodsModifiedMessage::ExchangePodsModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEPODSMODIFIEDMESSAGE;
}

