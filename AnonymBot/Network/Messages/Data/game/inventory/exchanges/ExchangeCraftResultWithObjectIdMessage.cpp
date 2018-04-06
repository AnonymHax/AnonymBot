#include "ExchangeCraftResultWithObjectIdMessage.h"

void ExchangeCraftResultWithObjectIdMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftResultWithObjectIdMessage(param1);
}

void ExchangeCraftResultWithObjectIdMessage::serializeAs_ExchangeCraftResultWithObjectIdMessage(Writer *param1)
{
  ExchangeCraftResultMessage::serializeAs_ExchangeCraftResultMessage(param1);
  if(this->objectGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftResultWithObjectIdMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element objectGenericId.";
  }
  else
  {
    param1->writeVarShort((int)this->objectGenericId);
    return;
  }
}

void ExchangeCraftResultWithObjectIdMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftResultWithObjectIdMessage(param1);
}

void ExchangeCraftResultWithObjectIdMessage::deserializeAs_ExchangeCraftResultWithObjectIdMessage(Reader *param1)
{
  ExchangeCraftResultMessage::deserialize(param1);
  this->objectGenericId = param1->readVarUhShort();
  if(this->objectGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftResultWithObjectIdMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element of ExchangeCraftResultWithObjectIdMessage.objectGenericId.";
  }
  else
  {
    return;
  }
}

ExchangeCraftResultWithObjectIdMessage::ExchangeCraftResultWithObjectIdMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE;
}

