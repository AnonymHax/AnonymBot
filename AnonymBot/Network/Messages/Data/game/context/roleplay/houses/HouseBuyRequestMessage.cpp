#include "HouseBuyRequestMessage.h"

void HouseBuyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseBuyRequestMessage(param1);
}

void HouseBuyRequestMessage::serializeAs_HouseBuyRequestMessage(Writer *param1)
{
  if(this->proposedPrice < 0)
  {
    qDebug()<<"ERREUR - HouseBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element proposedPrice.";
  }
  else
  {
    param1->writeVarInt((int)this->proposedPrice);
    return;
  }
}

void HouseBuyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseBuyRequestMessage(param1);
}

void HouseBuyRequestMessage::deserializeAs_HouseBuyRequestMessage(Reader *param1)
{
  this->proposedPrice = param1->readVarUhInt();
  if(this->proposedPrice < 0)
  {
    qDebug()<<"ERREUR - HouseBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element of HouseBuyRequestMessage.proposedPrice.";
  }
  else
  {
    return;
  }
}

HouseBuyRequestMessage::HouseBuyRequestMessage()
{
  m_type = MessageEnum::HOUSEBUYREQUESTMESSAGE;
}

