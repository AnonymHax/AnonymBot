#include "ExchangeOkMultiCraftMessage.h"

void ExchangeOkMultiCraftMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeOkMultiCraftMessage(param1);
}

void ExchangeOkMultiCraftMessage::serializeAs_ExchangeOkMultiCraftMessage(Writer *param1)
{
  if(this->initiatorId < 0 || this->initiatorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->initiatorId << ") on element initiatorId.";
  }
  else
  {
    param1->writeVarLong((double)this->initiatorId);
    if(this->otherId < 0 || this->otherId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->otherId << ") on element otherId.";
    }
    else
    {
      param1->writeVarLong((double)this->otherId);
      param1->writeByte(this->role);
      return;
    }
  }
}

void ExchangeOkMultiCraftMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeOkMultiCraftMessage(param1);
}

void ExchangeOkMultiCraftMessage::deserializeAs_ExchangeOkMultiCraftMessage(Reader *param1)
{
  this->initiatorId = param1->readVarUhLong();
  if(this->initiatorId < 0 || this->initiatorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->initiatorId << ") on element of ExchangeOkMultiCraftMessage.initiatorId.";
  }
  else
  {
    this->otherId = param1->readVarUhLong();
    if(this->otherId < 0 || this->otherId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->otherId << ") on element of ExchangeOkMultiCraftMessage.otherId.";
    }
    else
    {
      this->role = param1->readByte();
      return;
    }
  }
}

ExchangeOkMultiCraftMessage::ExchangeOkMultiCraftMessage()
{
  m_type = MessageEnum::EXCHANGEOKMULTICRAFTMESSAGE;
}

