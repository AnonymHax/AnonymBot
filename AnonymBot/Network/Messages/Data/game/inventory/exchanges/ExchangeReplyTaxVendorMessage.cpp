#include "ExchangeReplyTaxVendorMessage.h"

void ExchangeReplyTaxVendorMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeReplyTaxVendorMessage(param1);
}

void ExchangeReplyTaxVendorMessage::serializeAs_ExchangeReplyTaxVendorMessage(Writer *param1)
{
  if(this->objectValue < 0)
  {
    qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->objectValue << ") on element objectValue.";
  }
  else
  {
    param1->writeVarInt((int)this->objectValue);
    if(this->totalTaxValue < 0)
    {
      qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->totalTaxValue << ") on element totalTaxValue.";
    }
    else
    {
      param1->writeVarInt((int)this->totalTaxValue);
      return;
    }
  }
}

void ExchangeReplyTaxVendorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeReplyTaxVendorMessage(param1);
}

void ExchangeReplyTaxVendorMessage::deserializeAs_ExchangeReplyTaxVendorMessage(Reader *param1)
{
  this->objectValue = param1->readVarUhInt();
  if(this->objectValue < 0)
  {
    qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->objectValue << ") on element of ExchangeReplyTaxVendorMessage.objectValue.";
  }
  else
  {
    this->totalTaxValue = param1->readVarUhInt();
    if(this->totalTaxValue < 0)
    {
      qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->totalTaxValue << ") on element of ExchangeReplyTaxVendorMessage.totalTaxValue.";
    }
    else
    {
      return;
    }
  }
}

ExchangeReplyTaxVendorMessage::ExchangeReplyTaxVendorMessage()
{
  m_type = MessageEnum::EXCHANGEREPLYTAXVENDORMESSAGE;
}

