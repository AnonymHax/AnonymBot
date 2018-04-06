#include "ExchangeStoppedMessage.h"

void ExchangeStoppedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStoppedMessage(param1);
}

void ExchangeStoppedMessage::serializeAs_ExchangeStoppedMessage(Writer *param1)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStoppedMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarLong((double)this->id);
    return;
  }
}

void ExchangeStoppedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStoppedMessage(param1);
}

void ExchangeStoppedMessage::deserializeAs_ExchangeStoppedMessage(Reader *param1)
{
  this->id = param1->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStoppedMessage -"<<"Forbidden value (" << this->id << ") on element of ExchangeStoppedMessage.id.";
  }
  else
  {
    return;
  }
}

ExchangeStoppedMessage::ExchangeStoppedMessage()
{
  m_type = MessageEnum::EXCHANGESTOPPEDMESSAGE;
}

