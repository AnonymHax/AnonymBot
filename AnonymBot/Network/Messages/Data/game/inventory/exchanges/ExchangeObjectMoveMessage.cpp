#include "ExchangeObjectMoveMessage.h"

void ExchangeObjectMoveMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectMoveMessage(param1);
}

void ExchangeObjectMoveMessage::serializeAs_ExchangeObjectMoveMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    param1->writeVarInt((int)this->quantity);
    return;
  }
}

void ExchangeObjectMoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectMoveMessage(param1);
}

void ExchangeObjectMoveMessage::deserializeAs_ExchangeObjectMoveMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectMoveMessage.objectUID.";
  }
  else
  {
    this->quantity = param1->readVarInt();
    return;
  }
}

ExchangeObjectMoveMessage::ExchangeObjectMoveMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVEMESSAGE;
}

