#include "TaxCollectorMovementsOfflineMessage.h"

void TaxCollectorMovementsOfflineMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorMovementsOfflineMessage(param1);
}

void TaxCollectorMovementsOfflineMessage::serializeAs_TaxCollectorMovementsOfflineMessage(Writer *param1)
{
  param1->writeShort((short)this->movements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->movements.size())
  {
    (this->movements[_loc2_]).serializeAs_TaxCollectorMovement(param1);
    _loc2_++;
  }
}

void TaxCollectorMovementsOfflineMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorMovementsOfflineMessage(param1);
}

void TaxCollectorMovementsOfflineMessage::deserializeAs_TaxCollectorMovementsOfflineMessage(Reader *param1)
{
  TaxCollectorMovement _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = TaxCollectorMovement();
    _loc4_.deserialize(param1);
    this->movements.append(_loc4_);
    _loc3_++;
  }
}

TaxCollectorMovementsOfflineMessage::TaxCollectorMovementsOfflineMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE;
}

