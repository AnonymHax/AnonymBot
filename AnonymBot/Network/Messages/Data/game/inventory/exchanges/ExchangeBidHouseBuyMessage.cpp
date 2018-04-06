#include "ExchangeBidHouseBuyMessage.h"

void ExchangeBidHouseBuyMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseBuyMessage(param1);
}

void ExchangeBidHouseBuyMessage::serializeAs_ExchangeBidHouseBuyMessage(Writer *param1)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  else
  {
    param1->writeVarInt((int)this->uid);
    if(this->qty < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->qty << ") on element qty.";
    }
    else
    {
      param1->writeVarInt((int)this->qty);
      if(this->price < 0)
      {
        qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->price << ") on element price.";
      }
      else
      {
        param1->writeVarInt((int)this->price);
        return;
      }
    }
  }
}

void ExchangeBidHouseBuyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseBuyMessage(param1);
}

void ExchangeBidHouseBuyMessage::deserializeAs_ExchangeBidHouseBuyMessage(Reader *param1)
{
  this->uid = param1->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->uid << ") on element of ExchangeBidHouseBuyMessage.uid.";
  }
  else
  {
    this->qty = param1->readVarUhInt();
    if(this->qty < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->qty << ") on element of ExchangeBidHouseBuyMessage.qty.";
    }
    else
    {
      this->price = param1->readVarUhInt();
      if(this->price < 0)
      {
        qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->price << ") on element of ExchangeBidHouseBuyMessage.price.";
      }
      else
      {
        return;
      }
    }
  }
}

ExchangeBidHouseBuyMessage::ExchangeBidHouseBuyMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEBUYMESSAGE;
}

