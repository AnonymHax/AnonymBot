#include "ExchangeObjectRemovedMessage.h"

void ExchangeObjectRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectRemovedMessage(param1);
}

void ExchangeObjectRemovedMessage::serializeAs_ExchangeObjectRemovedMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    return;
  }
}

void ExchangeObjectRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectRemovedMessage(param1);
}

void ExchangeObjectRemovedMessage::deserializeAs_ExchangeObjectRemovedMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectRemovedMessage.objectUID.";
  }
  else
  {
    return;
  }
}

ExchangeObjectRemovedMessage::ExchangeObjectRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE;
}

