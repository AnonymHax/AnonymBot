#include "TaxCollectorMovementAddMessage.h"

void TaxCollectorMovementAddMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorMovementAddMessage(param1);
}

void TaxCollectorMovementAddMessage::serializeAs_TaxCollectorMovementAddMessage(Writer *param1)
{
  param1->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(param1);
}

void TaxCollectorMovementAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorMovementAddMessage(param1);
}

void TaxCollectorMovementAddMessage::deserializeAs_TaxCollectorMovementAddMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->informations = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->informations->deserialize(param1);
}

TaxCollectorMovementAddMessage::TaxCollectorMovementAddMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTADDMESSAGE;
}

