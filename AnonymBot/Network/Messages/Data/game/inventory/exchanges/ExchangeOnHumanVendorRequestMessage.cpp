#include "ExchangeOnHumanVendorRequestMessage.h"

void ExchangeOnHumanVendorRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeOnHumanVendorRequestMessage(param1);
}

void ExchangeOnHumanVendorRequestMessage::serializeAs_ExchangeOnHumanVendorRequestMessage(Writer *param1)
{
  if(this->humanVendorId < 0 || this->humanVendorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorId << ") on element humanVendorId.";
  }
  else
  {
    param1->writeVarLong((double)this->humanVendorId);
    if(this->humanVendorCell < 0 || this->humanVendorCell > 559)
    {
      qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorCell << ") on element humanVendorCell.";
    }
    else
    {
      param1->writeVarShort((int)this->humanVendorCell);
      return;
    }
  }
}

void ExchangeOnHumanVendorRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeOnHumanVendorRequestMessage(param1);
}

void ExchangeOnHumanVendorRequestMessage::deserializeAs_ExchangeOnHumanVendorRequestMessage(Reader *param1)
{
  this->humanVendorId = param1->readVarUhLong();
  if(this->humanVendorId < 0 || this->humanVendorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorId << ") on element of ExchangeOnHumanVendorRequestMessage.humanVendorId.";
  }
  else
  {
    this->humanVendorCell = param1->readVarUhShort();
    if(this->humanVendorCell < 0 || this->humanVendorCell > 559)
    {
      qDebug()<<"ERREUR - ExchangeOnHumanVendorRequestMessage -"<<"Forbidden value (" << this->humanVendorCell << ") on element of ExchangeOnHumanVendorRequestMessage.humanVendorCell.";
    }
    else
    {
      return;
    }
  }
}

ExchangeOnHumanVendorRequestMessage::ExchangeOnHumanVendorRequestMessage()
{
  m_type = MessageEnum::EXCHANGEONHUMANVENDORREQUESTMESSAGE;
}

