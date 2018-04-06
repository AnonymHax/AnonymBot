#include "HouseSoldMessage.h"

void HouseSoldMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseSoldMessage(param1);
}

void HouseSoldMessage::serializeAs_HouseSoldMessage(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseSoldMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    if(this->realPrice < 0)
    {
      qDebug()<<"ERREUR - HouseSoldMessage -"<<"Forbidden value (" << this->realPrice << ") on element realPrice.";
    }
    else
    {
      param1->writeVarInt((int)this->realPrice);
      param1->writeUTF(this->buyerName);
      return;
    }
  }
}

void HouseSoldMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseSoldMessage(param1);
}

void HouseSoldMessage::deserializeAs_HouseSoldMessage(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseSoldMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseSoldMessage.houseId.";
  }
  else
  {
    this->realPrice = param1->readVarUhInt();
    if(this->realPrice < 0)
    {
      qDebug()<<"ERREUR - HouseSoldMessage -"<<"Forbidden value (" << this->realPrice << ") on element of HouseSoldMessage.realPrice.";
    }
    else
    {
      this->buyerName = param1->readUTF();
      return;
    }
  }
}

HouseSoldMessage::HouseSoldMessage()
{
  m_type = MessageEnum::HOUSESOLDMESSAGE;
}

