#include "PaddockBuyRequestMessage.h"

void PaddockBuyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockBuyRequestMessage(param1);
}

void PaddockBuyRequestMessage::serializeAs_PaddockBuyRequestMessage(Writer *param1)
{
  if(this->proposedPrice < 0)
  {
    qDebug()<<"ERREUR - PaddockBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element proposedPrice.";
  }
  else
  {
    param1->writeVarInt((int)this->proposedPrice);
    return;
  }
}

void PaddockBuyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockBuyRequestMessage(param1);
}

void PaddockBuyRequestMessage::deserializeAs_PaddockBuyRequestMessage(Reader *param1)
{
  this->proposedPrice = param1->readVarUhInt();
  if(this->proposedPrice < 0)
  {
    qDebug()<<"ERREUR - PaddockBuyRequestMessage -"<<"Forbidden value (" << this->proposedPrice << ") on element of PaddockBuyRequestMessage.proposedPrice.";
  }
  else
  {
    return;
  }
}

PaddockBuyRequestMessage::PaddockBuyRequestMessage()
{
  m_type = MessageEnum::PADDOCKBUYREQUESTMESSAGE;
}

