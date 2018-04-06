#include "AllianceListMessage.h"

void AllianceListMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceListMessage(param1);
}

void AllianceListMessage::serializeAs_AllianceListMessage(Writer *param1)
{
  param1->writeShort((short)this->alliances.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->alliances.size())
  {
    qSharedPointerCast<AllianceFactSheetInformations>(this->alliances[_loc2_])->serializeAs_AllianceFactSheetInformations(param1);
    _loc2_++;
  }
}

void AllianceListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceListMessage(param1);
}

void AllianceListMessage::deserializeAs_AllianceListMessage(Reader *param1)
{
  QSharedPointer<AllianceFactSheetInformations> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
    _loc4_->deserialize(param1);
    this->alliances.append(_loc4_);
    _loc3_++;
  }
}

AllianceListMessage::AllianceListMessage()
{
  m_type = MessageEnum::ALLIANCELISTMESSAGE;
}

