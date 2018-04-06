#include "ExchangeReadyMessage.h"

void ExchangeReadyMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeReadyMessage(param1);
}

void ExchangeReadyMessage::serializeAs_ExchangeReadyMessage(Writer *param1)
{
  param1->writeBool(this->ready);
  if(this->step < 0)
  {
    qDebug()<<"ERREUR - ExchangeReadyMessage -"<<"Forbidden value (" << this->step << ") on element step.";
  }
  else
  {
    param1->writeVarShort((int)this->step);
    return;
  }
}

void ExchangeReadyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeReadyMessage(param1);
}

void ExchangeReadyMessage::deserializeAs_ExchangeReadyMessage(Reader *param1)
{
  this->ready = param1->readBool();
  this->step = param1->readVarUhShort();
  if(this->step < 0)
  {
    qDebug()<<"ERREUR - ExchangeReadyMessage -"<<"Forbidden value (" << this->step << ") on element of ExchangeReadyMessage.step.";
  }
  else
  {
    return;
  }
}

ExchangeReadyMessage::ExchangeReadyMessage()
{
  m_type = MessageEnum::EXCHANGEREADYMESSAGE;
}

