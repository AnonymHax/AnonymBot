#include "ExchangeBidPriceMessage.h"

void ExchangeBidPriceMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidPriceMessage(param1);
}

void ExchangeBidPriceMessage::serializeAs_ExchangeBidPriceMessage(Writer *param1)
{
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceMessage -"<<"Forbidden value (" << this->genericId << ") on element genericId.";
  }
  else
  {
    param1->writeVarShort((int)this->genericId);
    param1->writeVarInt((int)this->averagePrice);
    return;
  }
}

void ExchangeBidPriceMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidPriceMessage(param1);
}

void ExchangeBidPriceMessage::deserializeAs_ExchangeBidPriceMessage(Reader *param1)
{
  this->genericId = param1->readVarUhShort();
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceMessage -"<<"Forbidden value (" << this->genericId << ") on element of ExchangeBidPriceMessage.genericId.";
  }
  else
  {
    this->averagePrice = param1->readVarInt();
    return;
  }
}

ExchangeBidPriceMessage::ExchangeBidPriceMessage()
{
  m_type = MessageEnum::EXCHANGEBIDPRICEMESSAGE;
}

