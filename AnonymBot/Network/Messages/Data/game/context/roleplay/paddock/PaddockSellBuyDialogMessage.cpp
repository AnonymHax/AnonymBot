#include "PaddockSellBuyDialogMessage.h"

void PaddockSellBuyDialogMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockSellBuyDialogMessage(param1);
}

void PaddockSellBuyDialogMessage::serializeAs_PaddockSellBuyDialogMessage(Writer *param1)
{
  param1->writeBool(this->bsell);
  if(this->ownerId < 0)
  {
    qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->ownerId << ") on element ownerId.";
  }
  else
  {
    param1->writeVarInt((int)this->ownerId);
    if(this->price < 0)
    {
      qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->price << ") on element price.";
    }
    else
    {
      param1->writeVarInt((int)this->price);
      return;
    }
  }
}

void PaddockSellBuyDialogMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockSellBuyDialogMessage(param1);
}

void PaddockSellBuyDialogMessage::deserializeAs_PaddockSellBuyDialogMessage(Reader *param1)
{
  this->bsell = param1->readBool();
  this->ownerId = param1->readVarUhInt();
  if(this->ownerId < 0)
  {
    qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->ownerId << ") on element of PaddockSellBuyDialogMessage.ownerId.";
  }
  else
  {
    this->price = param1->readVarUhInt();
    if(this->price < 0)
    {
      qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->price << ") on element of PaddockSellBuyDialogMessage.price.";
    }
    else
    {
      return;
    }
  }
}

PaddockSellBuyDialogMessage::PaddockSellBuyDialogMessage()
{
  m_type = MessageEnum::PADDOCKSELLBUYDIALOGMESSAGE;
}

