#include "ExchangeRequestedTradeMessage.h"

void ExchangeRequestedTradeMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeRequestedTradeMessage(param1);
}

void ExchangeRequestedTradeMessage::serializeAs_ExchangeRequestedTradeMessage(Writer *param1)
{
  ExchangeRequestedMessage::serializeAs_ExchangeRequestedMessage(param1);
  if(this->source < 0 || this->source > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->source << ") on element source.";
  }
  else
  {
    param1->writeVarLong((double)this->source);
    if(this->target < 0 || this->target > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->target << ") on element target.";
    }
    else
    {
      param1->writeVarLong((double)this->target);
      return;
    }
  }
}

void ExchangeRequestedTradeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeRequestedTradeMessage(param1);
}

void ExchangeRequestedTradeMessage::deserializeAs_ExchangeRequestedTradeMessage(Reader *param1)
{
  ExchangeRequestedMessage::deserialize(param1);
  this->source = param1->readVarUhLong();
  if(this->source < 0 || this->source > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->source << ") on element of ExchangeRequestedTradeMessage.source.";
  }
  else
  {
    this->target = param1->readVarUhLong();
    if(this->target < 0 || this->target > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->target << ") on element of ExchangeRequestedTradeMessage.target.";
    }
    else
    {
      return;
    }
  }
}

ExchangeRequestedTradeMessage::ExchangeRequestedTradeMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE;
}

