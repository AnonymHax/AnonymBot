#include "TaxCollectorMovementRemoveMessage.h"

void TaxCollectorMovementRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorMovementRemoveMessage(param1);
}

void TaxCollectorMovementRemoveMessage::serializeAs_TaxCollectorMovementRemoveMessage(Writer *param1)
{
  param1->writeInt((int)this->collectorId);
}

void TaxCollectorMovementRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorMovementRemoveMessage(param1);
}

void TaxCollectorMovementRemoveMessage::deserializeAs_TaxCollectorMovementRemoveMessage(Reader *param1)
{
  this->collectorId = param1->readInt();
}

TaxCollectorMovementRemoveMessage::TaxCollectorMovementRemoveMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTREMOVEMESSAGE;
}

