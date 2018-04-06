#include "ExchangeWeightMessage.h"

void ExchangeWeightMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeWeightMessage(param1);
}

void ExchangeWeightMessage::serializeAs_ExchangeWeightMessage(Writer *param1)
{
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->currentWeight << ") on element currentWeight.";
  }
  else
  {
    param1->writeVarInt((int)this->currentWeight);
    if(this->maxWeight < 0)
    {
      qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->maxWeight << ") on element maxWeight.";
    }
    else
    {
      param1->writeVarInt((int)this->maxWeight);
      return;
    }
  }
}

void ExchangeWeightMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeWeightMessage(param1);
}

void ExchangeWeightMessage::deserializeAs_ExchangeWeightMessage(Reader *param1)
{
  this->currentWeight = param1->readVarUhInt();
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->currentWeight << ") on element of ExchangeWeightMessage.currentWeight.";
  }
  else
  {
    this->maxWeight = param1->readVarUhInt();
    if(this->maxWeight < 0)
    {
      qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->maxWeight << ") on element of ExchangeWeightMessage.maxWeight.";
    }
    else
    {
      return;
    }
  }
}

ExchangeWeightMessage::ExchangeWeightMessage()
{
  m_type = MessageEnum::EXCHANGEWEIGHTMESSAGE;
}

