#include "HouseToSellListMessage.h"

void HouseToSellListMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseToSellListMessage(param1);
}

void HouseToSellListMessage::serializeAs_HouseToSellListMessage(Writer *param1)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  else
  {
    param1->writeVarShort((int)this->pageIndex);
    if(this->totalPage < 0)
    {
      qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element totalPage.";
    }
    else
    {
      param1->writeVarShort((int)this->totalPage);
      param1->writeShort((short)this->houseList.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->houseList.size())
      {
        (this->houseList[_loc2_]).serializeAs_HouseInformationsForSell(param1);
        _loc2_++;
      }
      return;
    }
  }
}

void HouseToSellListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseToSellListMessage(param1);
}

void HouseToSellListMessage::deserializeAs_HouseToSellListMessage(Reader *param1)
{
  HouseInformationsForSell _loc4_ ;
  this->pageIndex = param1->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of HouseToSellListMessage.pageIndex.";
  }
  else
  {
    this->totalPage = param1->readVarUhShort();
    if(this->totalPage < 0)
    {
      qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element of HouseToSellListMessage.totalPage.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = HouseInformationsForSell();
        _loc4_.deserialize(param1);
        this->houseList.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

HouseToSellListMessage::HouseToSellListMessage()
{
  m_type = MessageEnum::HOUSETOSELLLISTMESSAGE;
}

