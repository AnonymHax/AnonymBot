#include "ExchangeObjectUseInWorkshopMessage.h"

void ExchangeObjectUseInWorkshopMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeObjectUseInWorkshopMessage(param1);
}

void ExchangeObjectUseInWorkshopMessage::serializeAs_ExchangeObjectUseInWorkshopMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectUseInWorkshopMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    param1->writeVarInt((int)this->quantity);
    return;
  }
}

void ExchangeObjectUseInWorkshopMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeObjectUseInWorkshopMessage(param1);
}

void ExchangeObjectUseInWorkshopMessage::deserializeAs_ExchangeObjectUseInWorkshopMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectUseInWorkshopMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectUseInWorkshopMessage.objectUID.";
  }
  else
  {
    this->quantity = param1->readVarInt();
    return;
  }
}

ExchangeObjectUseInWorkshopMessage::ExchangeObjectUseInWorkshopMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTUSEINWORKSHOPMESSAGE;
}

