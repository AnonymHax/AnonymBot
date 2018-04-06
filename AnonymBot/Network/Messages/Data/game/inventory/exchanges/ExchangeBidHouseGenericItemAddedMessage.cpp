#include "ExchangeBidHouseGenericItemAddedMessage.h"

void ExchangeBidHouseGenericItemAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseGenericItemAddedMessage(param1);
}

void ExchangeBidHouseGenericItemAddedMessage::serializeAs_ExchangeBidHouseGenericItemAddedMessage(Writer *param1)
{
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemAddedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element objGenericId.";
  }
  else
  {
    param1->writeVarShort((int)this->objGenericId);
    return;
  }
}

void ExchangeBidHouseGenericItemAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseGenericItemAddedMessage(param1);
}

void ExchangeBidHouseGenericItemAddedMessage::deserializeAs_ExchangeBidHouseGenericItemAddedMessage(Reader *param1)
{
  this->objGenericId = param1->readVarUhShort();
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemAddedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element of ExchangeBidHouseGenericItemAddedMessage.objGenericId.";
  }
  else
  {
    return;
  }
}

ExchangeBidHouseGenericItemAddedMessage::ExchangeBidHouseGenericItemAddedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE;
}

