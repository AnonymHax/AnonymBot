#include "ExchangeBidHousePriceMessage.h"

void ExchangeBidHousePriceMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHousePriceMessage(param1);
}

void ExchangeBidHousePriceMessage::serializeAs_ExchangeBidHousePriceMessage(Writer *param1)
{
  if(this->genId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHousePriceMessage -"<<"Forbidden value (" << this->genId << ") on element genId.";
  }
  else
  {
    param1->writeVarShort((int)this->genId);
    return;
  }
}

void ExchangeBidHousePriceMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHousePriceMessage(param1);
}

void ExchangeBidHousePriceMessage::deserializeAs_ExchangeBidHousePriceMessage(Reader *param1)
{
  this->genId = param1->readVarUhShort();
  if(this->genId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHousePriceMessage -"<<"Forbidden value (" << this->genId << ") on element of ExchangeBidHousePriceMessage.genId.";
  }
  else
  {
    return;
  }
}

ExchangeBidHousePriceMessage::ExchangeBidHousePriceMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEPRICEMESSAGE;
}

