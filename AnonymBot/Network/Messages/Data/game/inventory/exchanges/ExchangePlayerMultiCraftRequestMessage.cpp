#include "ExchangePlayerMultiCraftRequestMessage.h"

void ExchangePlayerMultiCraftRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangePlayerMultiCraftRequestMessage(param1);
}

void ExchangePlayerMultiCraftRequestMessage::serializeAs_ExchangePlayerMultiCraftRequestMessage(Writer *param1)
{
  ExchangeRequestMessage::serializeAs_ExchangeRequestMessage(param1);
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->target << ") on element target.";
  }
  else
  {
    param1->writeVarLong((double)this->target);
    if(this->skillId < 0)
    {
      qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
    }
    else
    {
      param1->writeVarInt((int)this->skillId);
      return;
    }
  }
}

void ExchangePlayerMultiCraftRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangePlayerMultiCraftRequestMessage(param1);
}

void ExchangePlayerMultiCraftRequestMessage::deserializeAs_ExchangePlayerMultiCraftRequestMessage(Reader *param1)
{
  ExchangeRequestMessage::deserialize(param1);
  this->target = param1->readVarUhLong();
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->target << ") on element of ExchangePlayerMultiCraftRequestMessage.target.";
  }
  else
  {
    this->skillId = param1->readVarUhInt();
    if(this->skillId < 0)
    {
      qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangePlayerMultiCraftRequestMessage.skillId.";
    }
    else
    {
      return;
    }
  }
}

ExchangePlayerMultiCraftRequestMessage::ExchangePlayerMultiCraftRequestMessage()
{
  m_type = MessageEnum::EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE;
  m_needsHash = true;
}

