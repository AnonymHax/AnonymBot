#include "ExchangeBidHouseSearchMessage.h"

void ExchangeBidHouseSearchMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseSearchMessage(param1);
}

void ExchangeBidHouseSearchMessage::serializeAs_ExchangeBidHouseSearchMessage(Writer *param1)
{
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->type << ") on element type.";
  }
  else
  {
    param1->writeVarInt((int)this->type);
    if(this->genId < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->genId << ") on element genId.";
    }
    else
    {
      param1->writeVarShort((int)this->genId);
      return;
    }
  }
}

void ExchangeBidHouseSearchMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseSearchMessage(param1);
}

void ExchangeBidHouseSearchMessage::deserializeAs_ExchangeBidHouseSearchMessage(Reader *param1)
{
  this->type = param1->readVarUhInt();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->type << ") on element of ExchangeBidHouseSearchMessage.type.";
  }
  else
  {
    this->genId = param1->readVarUhShort();
    if(this->genId < 0)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseSearchMessage -"<<"Forbidden value (" << this->genId << ") on element of ExchangeBidHouseSearchMessage.genId.";
    }
    else
    {
      return;
    }
  }
}

ExchangeBidHouseSearchMessage::ExchangeBidHouseSearchMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSESEARCHMESSAGE;
}

