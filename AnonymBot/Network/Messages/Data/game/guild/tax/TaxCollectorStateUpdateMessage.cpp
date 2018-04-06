#include "TaxCollectorStateUpdateMessage.h"

void TaxCollectorStateUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorStateUpdateMessage(param1);
}

void TaxCollectorStateUpdateMessage::serializeAs_TaxCollectorStateUpdateMessage(Writer *param1)
{
  param1->writeInt((int)this->uniqueId);
  param1->writeByte(this->state);
}

void TaxCollectorStateUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorStateUpdateMessage(param1);
}

void TaxCollectorStateUpdateMessage::deserializeAs_TaxCollectorStateUpdateMessage(Reader *param1)
{
  this->uniqueId = param1->readInt();
  this->state = param1->readByte();
}

TaxCollectorStateUpdateMessage::TaxCollectorStateUpdateMessage()
{
  m_type = MessageEnum::TAXCOLLECTORSTATEUPDATEMESSAGE;
}

