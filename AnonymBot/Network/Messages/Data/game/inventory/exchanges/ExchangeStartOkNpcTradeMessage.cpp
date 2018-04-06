#include "ExchangeStartOkNpcTradeMessage.h"

void ExchangeStartOkNpcTradeMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkNpcTradeMessage(param1);
}

void ExchangeStartOkNpcTradeMessage::serializeAs_ExchangeStartOkNpcTradeMessage(Writer *param1)
{
  if(this->npcId < -9.007199254740992E15 || this->npcId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcTradeMessage -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  else
  {
    param1->writeDouble(this->npcId);
    return;
  }
}

void ExchangeStartOkNpcTradeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkNpcTradeMessage(param1);
}

void ExchangeStartOkNpcTradeMessage::deserializeAs_ExchangeStartOkNpcTradeMessage(Reader *param1)
{
  this->npcId = param1->readDouble();
  if(this->npcId < -9.007199254740992E15 || this->npcId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcTradeMessage -"<<"Forbidden value (" << this->npcId << ") on element of ExchangeStartOkNpcTradeMessage.npcId.";
  }
  else
  {
    return;
  }
}

ExchangeStartOkNpcTradeMessage::ExchangeStartOkNpcTradeMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKNPCTRADEMESSAGE;
}

