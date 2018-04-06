#include "ExchangeBidHouseTypeMessage.h"

void ExchangeBidHouseTypeMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseTypeMessage(param1);
}

void ExchangeBidHouseTypeMessage::serializeAs_ExchangeBidHouseTypeMessage(Writer *param1)
{
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseTypeMessage -"<<"Forbidden value (" << this->type << ") on element type.";
  }
  else
  {
    param1->writeVarInt((int)this->type);
    return;
  }
}

void ExchangeBidHouseTypeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseTypeMessage(param1);
}

void ExchangeBidHouseTypeMessage::deserializeAs_ExchangeBidHouseTypeMessage(Reader *param1)
{
  this->type = param1->readVarUhInt();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseTypeMessage -"<<"Forbidden value (" << this->type << ") on element of ExchangeBidHouseTypeMessage.type.";
  }
  else
  {
    return;
  }
}

ExchangeBidHouseTypeMessage::ExchangeBidHouseTypeMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSETYPEMESSAGE;
}

