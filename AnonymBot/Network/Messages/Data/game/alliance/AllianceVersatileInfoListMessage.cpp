#include "AllianceVersatileInfoListMessage.h"

void AllianceVersatileInfoListMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceVersatileInfoListMessage(param1);
}

void AllianceVersatileInfoListMessage::serializeAs_AllianceVersatileInfoListMessage(Writer *param1)
{
  param1->writeShort((short)this->alliances.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->alliances.size())
  {
    (this->alliances[_loc2_]).serializeAs_AllianceVersatileInformations(param1);
    _loc2_++;
  }
}

void AllianceVersatileInfoListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceVersatileInfoListMessage(param1);
}

void AllianceVersatileInfoListMessage::deserializeAs_AllianceVersatileInfoListMessage(Reader *param1)
{
  AllianceVersatileInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = AllianceVersatileInformations();
    _loc4_.deserialize(param1);
    this->alliances.append(_loc4_);
    _loc3_++;
  }
}

AllianceVersatileInfoListMessage::AllianceVersatileInfoListMessage()
{
  m_type = MessageEnum::ALLIANCEVERSATILEINFOLISTMESSAGE;
}

