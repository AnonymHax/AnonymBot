#include "PaddockSellRequestMessage.h"

void PaddockSellRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockSellRequestMessage(param1);
}

void PaddockSellRequestMessage::serializeAs_PaddockSellRequestMessage(Writer *param1)
{
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - PaddockSellRequestMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  else
  {
    param1->writeVarInt((int)this->price);
    param1->writeBool(this->forSale);
    return;
  }
}

void PaddockSellRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockSellRequestMessage(param1);
}

void PaddockSellRequestMessage::deserializeAs_PaddockSellRequestMessage(Reader *param1)
{
  this->price = param1->readVarUhInt();
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - PaddockSellRequestMessage -"<<"Forbidden value (" << this->price << ") on element of PaddockSellRequestMessage.price.";
  }
  else
  {
    this->forSale = param1->readBool();
    return;
  }
}

PaddockSellRequestMessage::PaddockSellRequestMessage()
{
  m_type = MessageEnum::PADDOCKSELLREQUESTMESSAGE;
}

