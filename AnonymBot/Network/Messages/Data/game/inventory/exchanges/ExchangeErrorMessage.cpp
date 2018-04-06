#include "ExchangeErrorMessage.h"

void ExchangeErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeErrorMessage(param1);
}

void ExchangeErrorMessage::serializeAs_ExchangeErrorMessage(Writer *param1)
{
  param1->writeByte(this->errorType);
}

void ExchangeErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeErrorMessage(param1);
}

void ExchangeErrorMessage::deserializeAs_ExchangeErrorMessage(Reader *param1)
{
  this->errorType = param1->readByte();
}

ExchangeErrorMessage::ExchangeErrorMessage()
{
  m_type = MessageEnum::EXCHANGEERRORMESSAGE;
}

