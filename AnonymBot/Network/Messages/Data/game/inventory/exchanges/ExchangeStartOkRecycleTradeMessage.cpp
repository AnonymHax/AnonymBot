#include "ExchangeStartOkRecycleTradeMessage.h"

void ExchangeStartOkRecycleTradeMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkRecycleTradeMessage(param1);
}

void ExchangeStartOkRecycleTradeMessage::serializeAs_ExchangeStartOkRecycleTradeMessage(Writer *param1)
{
  if(this->percentToPrism < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPrism << ") on element percentToPrism.";
  }
  else
  {
    param1->writeShort((short)this->percentToPrism);
    if(this->percentToPlayer < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPlayer << ") on element percentToPlayer.";
    }
    else
    {
      param1->writeShort((short)this->percentToPlayer);
      return;
    }
  }
}

void ExchangeStartOkRecycleTradeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkRecycleTradeMessage(param1);
}

void ExchangeStartOkRecycleTradeMessage::deserializeAs_ExchangeStartOkRecycleTradeMessage(Reader *param1)
{
  this->percentToPrism = param1->readShort();
  if(this->percentToPrism < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPrism << ") on element of ExchangeStartOkRecycleTradeMessage.percentToPrism.";
  }
  else
  {
    this->percentToPlayer = param1->readShort();
    if(this->percentToPlayer < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPlayer << ") on element of ExchangeStartOkRecycleTradeMessage.percentToPlayer.";
    }
    else
    {
      return;
    }
  }
}

ExchangeStartOkRecycleTradeMessage::ExchangeStartOkRecycleTradeMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKRECYCLETRADEMESSAGE;
}

