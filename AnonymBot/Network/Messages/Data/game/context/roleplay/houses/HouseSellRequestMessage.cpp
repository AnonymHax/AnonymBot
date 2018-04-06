#include "HouseSellRequestMessage.h"

void HouseSellRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseSellRequestMessage(param1);
}

void HouseSellRequestMessage::serializeAs_HouseSellRequestMessage(Writer *param1)
{
  if(this->amount < 0)
  {
    qDebug()<<"ERREUR - HouseSellRequestMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  else
  {
    param1->writeVarInt((int)this->amount);
    param1->writeBool(this->forSale);
    return;
  }
}

void HouseSellRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseSellRequestMessage(param1);
}

void HouseSellRequestMessage::deserializeAs_HouseSellRequestMessage(Reader *param1)
{
  this->amount = param1->readVarUhInt();
  if(this->amount < 0)
  {
    qDebug()<<"ERREUR - HouseSellRequestMessage -"<<"Forbidden value (" << this->amount << ") on element of HouseSellRequestMessage.amount.";
  }
  else
  {
    this->forSale = param1->readBool();
    return;
  }
}

HouseSellRequestMessage::HouseSellRequestMessage()
{
  m_type = MessageEnum::HOUSESELLREQUESTMESSAGE;
}

