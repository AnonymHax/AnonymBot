#include "ExchangeIsReadyMessage.h"

void ExchangeIsReadyMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeIsReadyMessage(param1);
}

void ExchangeIsReadyMessage::serializeAs_ExchangeIsReadyMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeIsReadyMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    param1->writeBool(this->ready);
    return;
  }
}

void ExchangeIsReadyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeIsReadyMessage(param1);
}

void ExchangeIsReadyMessage::deserializeAs_ExchangeIsReadyMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeIsReadyMessage -"<<"Forbidden value (" << this->id << ") on element of ExchangeIsReadyMessage.id.";
  }
  else
  {
    this->ready = param1->readBool();
    return;
  }
}

ExchangeIsReadyMessage::ExchangeIsReadyMessage()
{
  m_type = MessageEnum::EXCHANGEISREADYMESSAGE;
}

