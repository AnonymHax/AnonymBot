#include "ExchangeBidHouseListMessage.h"

void ExchangeBidHouseListMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseListMessage(param1);
}

void ExchangeBidHouseListMessage::serializeAs_ExchangeBidHouseListMessage(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseListMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    return;
  }
}

void ExchangeBidHouseListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseListMessage(param1);
}

void ExchangeBidHouseListMessage::deserializeAs_ExchangeBidHouseListMessage(Reader *param1)
{
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseListMessage -"<<"Forbidden value (" << this->id << ") on element of ExchangeBidHouseListMessage.id.";
  }
  else
  {
    return;
  }
}

ExchangeBidHouseListMessage::ExchangeBidHouseListMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSELISTMESSAGE;
}

