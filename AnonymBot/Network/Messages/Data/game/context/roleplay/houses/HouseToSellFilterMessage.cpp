#include "HouseToSellFilterMessage.h"

void HouseToSellFilterMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseToSellFilterMessage(param1);
}

void HouseToSellFilterMessage::serializeAs_HouseToSellFilterMessage(Writer *param1)
{
  param1->writeInt((int)this->areaId);
  if(this->atLeastNbRoom < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbRoom << ") on element atLeastNbRoom.";
  }
  else
  {
    param1->writeByte(this->atLeastNbRoom);
    if(this->atLeastNbChest < 0)
    {
      qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbChest << ") on element atLeastNbChest.";
    }
    else
    {
      param1->writeByte(this->atLeastNbChest);
      if(this->skillRequested < 0)
      {
        qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->skillRequested << ") on element skillRequested.";
      }
      else
      {
        param1->writeVarShort((int)this->skillRequested);
        if(this->maxPrice < 0)
        {
          qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element maxPrice.";
        }
        else
        {
          param1->writeVarInt((int)this->maxPrice);
          return;
        }
      }
    }
  }
}

void HouseToSellFilterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseToSellFilterMessage(param1);
}

void HouseToSellFilterMessage::deserializeAs_HouseToSellFilterMessage(Reader *param1)
{
  this->areaId = param1->readInt();
  this->atLeastNbRoom = param1->readByte();
  if(this->atLeastNbRoom < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbRoom << ") on element of HouseToSellFilterMessage.atLeastNbRoom.";
  }
  else
  {
    this->atLeastNbChest = param1->readByte();
    if(this->atLeastNbChest < 0)
    {
      qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbChest << ") on element of HouseToSellFilterMessage.atLeastNbChest.";
    }
    else
    {
      this->skillRequested = param1->readVarUhShort();
      if(this->skillRequested < 0)
      {
        qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->skillRequested << ") on element of HouseToSellFilterMessage.skillRequested.";
      }
      else
      {
        this->maxPrice = param1->readVarUhInt();
        if(this->maxPrice < 0)
        {
          qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element of HouseToSellFilterMessage.maxPrice.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

HouseToSellFilterMessage::HouseToSellFilterMessage()
{
  m_type = MessageEnum::HOUSETOSELLFILTERMESSAGE;
}

