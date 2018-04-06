#include "HouseBuyResultMessage.h"

void HouseBuyResultMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseBuyResultMessage(param1);
}

void HouseBuyResultMessage::serializeAs_HouseBuyResultMessage(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    param1->writeBool(this->bought);
    if(this->realPrice < 0)
    {
      qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element realPrice.";
    }
    else
    {
      param1->writeVarInt((int)this->realPrice);
      return;
    }
  }
}

void HouseBuyResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseBuyResultMessage(param1);
}

void HouseBuyResultMessage::deserializeAs_HouseBuyResultMessage(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseBuyResultMessage.houseId.";
  }
  else
  {
    this->bought = param1->readBool();
    this->realPrice = param1->readVarUhInt();
    if(this->realPrice < 0)
    {
      qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element of HouseBuyResultMessage.realPrice.";
    }
    else
    {
      return;
    }
  }
}

HouseBuyResultMessage::HouseBuyResultMessage()
{
  m_type = MessageEnum::HOUSEBUYRESULTMESSAGE;
}

