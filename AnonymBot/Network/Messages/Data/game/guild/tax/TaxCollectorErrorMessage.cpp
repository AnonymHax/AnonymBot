#include "TaxCollectorErrorMessage.h"

void TaxCollectorErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorErrorMessage(param1);
}

void TaxCollectorErrorMessage::serializeAs_TaxCollectorErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void TaxCollectorErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorErrorMessage(param1);
}

void TaxCollectorErrorMessage::deserializeAs_TaxCollectorErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
}

TaxCollectorErrorMessage::TaxCollectorErrorMessage()
{
  m_type = MessageEnum::TAXCOLLECTORERRORMESSAGE;
}

