#include "ExchangeStartOkCraftWithInformationMessage.h"

void ExchangeStartOkCraftWithInformationMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkCraftWithInformationMessage(param1);
}

void ExchangeStartOkCraftWithInformationMessage::serializeAs_ExchangeStartOkCraftWithInformationMessage(Writer *param1)
{
  ExchangeStartOkCraftMessage::serializeAs_ExchangeStartOkCraftMessage(param1);
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkCraftWithInformationMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  else
  {
    param1->writeVarInt((int)this->skillId);
    return;
  }
}

void ExchangeStartOkCraftWithInformationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkCraftWithInformationMessage(param1);
}

void ExchangeStartOkCraftWithInformationMessage::deserializeAs_ExchangeStartOkCraftWithInformationMessage(Reader *param1)
{
  ExchangeStartOkCraftMessage::deserialize(param1);
  this->skillId = param1->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkCraftWithInformationMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangeStartOkCraftWithInformationMessage.skillId.";
  }
  else
  {
    return;
  }
}

ExchangeStartOkCraftWithInformationMessage::ExchangeStartOkCraftWithInformationMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE;
}

