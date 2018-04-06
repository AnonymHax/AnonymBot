#include "ExchangeObjectRemovedFromBagMessage.h"

void ExchangeObjectRemovedFromBagMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectRemovedFromBagMessage(param1);
}

void ExchangeObjectRemovedFromBagMessage::serializeAs_ExchangeObjectRemovedFromBagMessage(Writer *param1)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(param1);
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedFromBagMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    return;
  }
}

void ExchangeObjectRemovedFromBagMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectRemovedFromBagMessage(param1);
}

void ExchangeObjectRemovedFromBagMessage::deserializeAs_ExchangeObjectRemovedFromBagMessage(Reader *param1)
{
  ExchangeObjectMessage::deserialize(param1);
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedFromBagMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectRemovedFromBagMessage.objectUID.";
  }
  else
  {
    return;
  }
}

ExchangeObjectRemovedFromBagMessage::ExchangeObjectRemovedFromBagMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE;
}

