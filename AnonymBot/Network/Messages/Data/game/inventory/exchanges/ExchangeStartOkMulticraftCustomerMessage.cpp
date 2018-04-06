#include "ExchangeStartOkMulticraftCustomerMessage.h"

void ExchangeStartOkMulticraftCustomerMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkMulticraftCustomerMessage(param1);
}

void ExchangeStartOkMulticraftCustomerMessage::serializeAs_ExchangeStartOkMulticraftCustomerMessage(Writer *param1)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  else
  {
    param1->writeVarInt((int)this->skillId);
    if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
    {
      qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element crafterJobLevel.";
    }
    else
    {
      param1->writeByte(this->crafterJobLevel);
      return;
    }
  }
}

void ExchangeStartOkMulticraftCustomerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkMulticraftCustomerMessage(param1);
}

void ExchangeStartOkMulticraftCustomerMessage::deserializeAs_ExchangeStartOkMulticraftCustomerMessage(Reader *param1)
{
  this->skillId = param1->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangeStartOkMulticraftCustomerMessage.skillId.";
  }
  else
  {
    this->crafterJobLevel = param1->readUByte();
    if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
    {
      qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element of ExchangeStartOkMulticraftCustomerMessage.crafterJobLevel.";
    }
    else
    {
      return;
    }
  }
}

ExchangeStartOkMulticraftCustomerMessage::ExchangeStartOkMulticraftCustomerMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE;
}

