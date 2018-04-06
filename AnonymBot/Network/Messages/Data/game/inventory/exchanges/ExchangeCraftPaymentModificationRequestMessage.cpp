#include "ExchangeCraftPaymentModificationRequestMessage.h"

void ExchangeCraftPaymentModificationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftPaymentModificationRequestMessage(param1);
}

void ExchangeCraftPaymentModificationRequestMessage::serializeAs_ExchangeCraftPaymentModificationRequestMessage(Writer *param1)
{
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModificationRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  else
  {
    param1->writeVarInt((int)this->quantity);
    return;
  }
}

void ExchangeCraftPaymentModificationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftPaymentModificationRequestMessage(param1);
}

void ExchangeCraftPaymentModificationRequestMessage::deserializeAs_ExchangeCraftPaymentModificationRequestMessage(Reader *param1)
{
  this->quantity = param1->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModificationRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeCraftPaymentModificationRequestMessage.quantity.";
  }
  else
  {
    return;
  }
}

ExchangeCraftPaymentModificationRequestMessage::ExchangeCraftPaymentModificationRequestMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE;
}

