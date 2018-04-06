#include "HouseToSellListRequestMessage.h"

void HouseToSellListRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseToSellListRequestMessage(param1);
}

void HouseToSellListRequestMessage::serializeAs_HouseToSellListRequestMessage(Writer *param1)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  else
  {
    param1->writeVarShort((int)this->pageIndex);
    return;
  }
}

void HouseToSellListRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseToSellListRequestMessage(param1);
}

void HouseToSellListRequestMessage::deserializeAs_HouseToSellListRequestMessage(Reader *param1)
{
  this->pageIndex = param1->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of HouseToSellListRequestMessage.pageIndex.";
  }
  else
  {
    return;
  }
}

HouseToSellListRequestMessage::HouseToSellListRequestMessage()
{
  m_type = MessageEnum::HOUSETOSELLLISTREQUESTMESSAGE;
}

