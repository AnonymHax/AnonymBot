#include "PaddockToSellListRequestMessage.h"

void PaddockToSellListRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockToSellListRequestMessage(param1);
}

void PaddockToSellListRequestMessage::serializeAs_PaddockToSellListRequestMessage(Writer *param1)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  else
  {
    param1->writeVarShort((int)this->pageIndex);
    return;
  }
}

void PaddockToSellListRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockToSellListRequestMessage(param1);
}

void PaddockToSellListRequestMessage::deserializeAs_PaddockToSellListRequestMessage(Reader *param1)
{
  this->pageIndex = param1->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of PaddockToSellListRequestMessage.pageIndex.";
  }
  else
  {
    return;
  }
}

PaddockToSellListRequestMessage::PaddockToSellListRequestMessage()
{
  m_type = MessageEnum::PADDOCKTOSELLLISTREQUESTMESSAGE;
}

