#include "PaddockToSellListMessage.h"

void PaddockToSellListMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockToSellListMessage(param1);
}

void PaddockToSellListMessage::serializeAs_PaddockToSellListMessage(Writer *param1)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  else
  {
    param1->writeVarShort((int)this->pageIndex);
    if(this->totalPage < 0)
    {
      qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element totalPage.";
    }
    else
    {
      param1->writeVarShort((int)this->totalPage);
      param1->writeShort((short)this->paddockList.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->paddockList.size())
      {
        (this->paddockList[_loc2_]).serializeAs_PaddockInformationsForSell(param1);
        _loc2_++;
      }
      return;
    }
  }
}

void PaddockToSellListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockToSellListMessage(param1);
}

void PaddockToSellListMessage::deserializeAs_PaddockToSellListMessage(Reader *param1)
{
  PaddockInformationsForSell _loc4_ ;
  this->pageIndex = param1->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of PaddockToSellListMessage.pageIndex.";
  }
  else
  {
    this->totalPage = param1->readVarUhShort();
    if(this->totalPage < 0)
    {
      qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element of PaddockToSellListMessage.totalPage.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = PaddockInformationsForSell();
        _loc4_.deserialize(param1);
        this->paddockList.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

PaddockToSellListMessage::PaddockToSellListMessage()
{
  m_type = MessageEnum::PADDOCKTOSELLLISTMESSAGE;
}

