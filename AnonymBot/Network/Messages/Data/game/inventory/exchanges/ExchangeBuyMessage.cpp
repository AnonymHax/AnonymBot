#include "ExchangeBuyMessage.h"

void ExchangeBuyMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBuyMessage(param1);
}

void ExchangeBuyMessage::serializeAs_ExchangeBuyMessage(Writer *param1)
{
  if(this->objectToBuyId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->objectToBuyId << ") on element objectToBuyId.";
  }
  else
  {
    param1->writeVarInt((int)this->objectToBuyId);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ExchangeBuyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBuyMessage(param1);
}

void ExchangeBuyMessage::deserializeAs_ExchangeBuyMessage(Reader *param1)
{
  this->objectToBuyId = param1->readVarUhInt();
  if(this->objectToBuyId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->objectToBuyId << ") on element of ExchangeBuyMessage.objectToBuyId.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeBuyMessage.quantity.";
    }
    else
    {
      return;
    }
  }
}

ExchangeBuyMessage::ExchangeBuyMessage()
{
  m_type = MessageEnum::EXCHANGEBUYMESSAGE;
}

