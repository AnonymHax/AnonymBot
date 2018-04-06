#include "AbstractTaxCollectorListMessage.h"

void AbstractTaxCollectorListMessage::serialize(Writer *param1)
{
  this->serializeAs_AbstractTaxCollectorListMessage(param1);
}

void AbstractTaxCollectorListMessage::serializeAs_AbstractTaxCollectorListMessage(Writer *param1)
{
  param1->writeShort((short)this->informations.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->informations.size())
  {
    param1->writeShort((short)qSharedPointerCast<TaxCollectorInformations>(this->informations[_loc2_])->getTypes().last());
    qSharedPointerCast<TaxCollectorInformations>(this->informations[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void AbstractTaxCollectorListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractTaxCollectorListMessage(param1);
}

void AbstractTaxCollectorListMessage::deserializeAs_AbstractTaxCollectorListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<TaxCollectorInformations> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->informations.append(_loc5_);
    _loc3_++;
  }
}

AbstractTaxCollectorListMessage::AbstractTaxCollectorListMessage()
{
  m_type = MessageEnum::ABSTRACTTAXCOLLECTORLISTMESSAGE;
}

