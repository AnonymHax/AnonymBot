#include "ExchangeBidHouseGenericItemRemovedMessage.h"

void ExchangeBidHouseGenericItemRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeBidHouseGenericItemRemovedMessage(param1);
}

void ExchangeBidHouseGenericItemRemovedMessage::serializeAs_ExchangeBidHouseGenericItemRemovedMessage(Writer *param1)
{
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemRemovedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element objGenericId.";
  }
  else
  {
    param1->writeVarShort((int)this->objGenericId);
    return;
  }
}

void ExchangeBidHouseGenericItemRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeBidHouseGenericItemRemovedMessage(param1);
}

void ExchangeBidHouseGenericItemRemovedMessage::deserializeAs_ExchangeBidHouseGenericItemRemovedMessage(Reader *param1)
{
  this->objGenericId = param1->readVarUhShort();
  if(this->objGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseGenericItemRemovedMessage -"<<"Forbidden value (" << this->objGenericId << ") on element of ExchangeBidHouseGenericItemRemovedMessage.objGenericId.";
  }
  else
  {
    return;
  }
}

ExchangeBidHouseGenericItemRemovedMessage::ExchangeBidHouseGenericItemRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE;
}

