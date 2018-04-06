#include "ExchangeWaitingResultMessage.h"

void ExchangeWaitingResultMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeWaitingResultMessage(param1);
}

void ExchangeWaitingResultMessage::serializeAs_ExchangeWaitingResultMessage(Writer *param1)
{
  param1->writeBool(this->bwait);
}

void ExchangeWaitingResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeWaitingResultMessage(param1);
}

void ExchangeWaitingResultMessage::deserializeAs_ExchangeWaitingResultMessage(Reader *param1)
{
  this->bwait = param1->readBool();
}

ExchangeWaitingResultMessage::ExchangeWaitingResultMessage()
{
  m_type = MessageEnum::EXCHANGEWAITINGRESULTMESSAGE;
}

