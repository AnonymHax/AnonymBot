#include "ExchangeItemAutoCraftStopedMessage.h"

void ExchangeItemAutoCraftStopedMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeItemAutoCraftStopedMessage(param1);
}

void ExchangeItemAutoCraftStopedMessage::serializeAs_ExchangeItemAutoCraftStopedMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void ExchangeItemAutoCraftStopedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeItemAutoCraftStopedMessage(param1);
}

void ExchangeItemAutoCraftStopedMessage::deserializeAs_ExchangeItemAutoCraftStopedMessage(Reader *param1)
{
  this->reason = param1->readByte();
}

ExchangeItemAutoCraftStopedMessage::ExchangeItemAutoCraftStopedMessage()
{
  m_type = MessageEnum::EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE;
}

