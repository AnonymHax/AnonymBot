#include "ExchangeBidHouseBuyResultMessage.h"

void ExchangeBidHouseBuyResultMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseBuyResultMessage(param1);
}

void ExchangeBidHouseBuyResultMessage::serializeAs_ExchangeBidHouseBuyResultMessage(Writer *param1)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyResultMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  else
  {
    param1->writeVarInt((int)this->uid);
    param1->writeBool(this->bought);
    return;
  }
}

void ExchangeBidHouseBuyResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseBuyResultMessage(param1);
}

void ExchangeBidHouseBuyResultMessage::deserializeAs_ExchangeBidHouseBuyResultMessage(Reader *param1)
{
  this->uid = param1->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyResultMessage -"<<"Forbidden value (" << this->uid << ") on element of ExchangeBidHouseBuyResultMessage.uid.";
  }
  else
  {
    this->bought = param1->readBool();
    return;
  }
}

ExchangeBidHouseBuyResultMessage::ExchangeBidHouseBuyResultMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEBUYRESULTMESSAGE;
}

