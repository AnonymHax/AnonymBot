#include "ExchangeCraftPaymentModifiedMessage.h"

void ExchangeCraftPaymentModifiedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftPaymentModifiedMessage(param1);
}

void ExchangeCraftPaymentModifiedMessage::serializeAs_ExchangeCraftPaymentModifiedMessage(Writer *param1)
{
  if(this->goldSum < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModifiedMessage -"<<"Forbidden value (" << this->goldSum << ") on element goldSum.";
  }
  else
  {
    param1->writeVarInt((int)this->goldSum);
    return;
  }
}

void ExchangeCraftPaymentModifiedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftPaymentModifiedMessage(param1);
}

void ExchangeCraftPaymentModifiedMessage::deserializeAs_ExchangeCraftPaymentModifiedMessage(Reader *param1)
{
  this->goldSum = param1->readVarUhInt();
  if(this->goldSum < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModifiedMessage -"<<"Forbidden value (" << this->goldSum << ") on element of ExchangeCraftPaymentModifiedMessage.goldSum.";
  }
  else
  {
    return;
  }
}

ExchangeCraftPaymentModifiedMessage::ExchangeCraftPaymentModifiedMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE;
}

