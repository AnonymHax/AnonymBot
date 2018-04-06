#include "PurchasableDialogMessage.h"

void PurchasableDialogMessage::serialize(Writer *param1)
{
  this->serializeAs_PurchasableDialogMessage(param1);
}

void PurchasableDialogMessage::serializeAs_PurchasableDialogMessage(Writer *param1)
{
  param1->writeBool(this->buyOrSell);
  if(this->purchasableId < 0)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->purchasableId << ") on element purchasableId.";
  }
  else
  {
    param1->writeVarInt((int)this->purchasableId);
    if(this->price < 0)
    {
      qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->price << ") on element price.";
    }
    else
    {
      param1->writeVarInt((int)this->price);
      return;
    }
  }
}

void PurchasableDialogMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PurchasableDialogMessage(param1);
}

void PurchasableDialogMessage::deserializeAs_PurchasableDialogMessage(Reader *param1)
{
  this->buyOrSell = param1->readBool();
  this->purchasableId = param1->readVarUhInt();
  if(this->purchasableId < 0)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->purchasableId << ") on element of PurchasableDialogMessage.purchasableId.";
  }
  else
  {
    this->price = param1->readVarUhInt();
    if(this->price < 0)
    {
      qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->price << ") on element of PurchasableDialogMessage.price.";
    }
    else
    {
      return;
    }
  }
}

PurchasableDialogMessage::PurchasableDialogMessage()
{
  m_type = MessageEnum::PURCHASABLEDIALOGMESSAGE;
}

