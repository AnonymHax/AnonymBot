#include "ExchangePlayerRequestMessage.h"

void ExchangePlayerRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangePlayerRequestMessage(param1);
}

void ExchangePlayerRequestMessage::serializeAs_ExchangePlayerRequestMessage(Writer *param1)
{
  ExchangeRequestMessage::serializeAs_ExchangeRequestMessage(param1);
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangePlayerRequestMessage -"<<"Forbidden value (" << this->target << ") on element target.";
  }
  else
  {
    param1->writeVarLong((double)this->target);
    return;
  }
}

void ExchangePlayerRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangePlayerRequestMessage(param1);
}

void ExchangePlayerRequestMessage::deserializeAs_ExchangePlayerRequestMessage(Reader *param1)
{
  ExchangeRequestMessage::deserialize(param1);
  this->target = param1->readVarUhLong();
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangePlayerRequestMessage -"<<"Forbidden value (" << this->target << ") on element of ExchangePlayerRequestMessage.target.";
  }
  else
  {
    return;
  }
}

ExchangePlayerRequestMessage::ExchangePlayerRequestMessage()
{
  m_type = MessageEnum::EXCHANGEPLAYERREQUESTMESSAGE;
  m_needsHash = true;
}

