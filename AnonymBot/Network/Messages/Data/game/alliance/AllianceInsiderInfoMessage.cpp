#include "AllianceInsiderInfoMessage.h"

void AllianceInsiderInfoMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceInsiderInfoMessage(param1);
}

void AllianceInsiderInfoMessage::serializeAs_AllianceInsiderInfoMessage(Writer *param1)
{
  this->allianceInfos->serializeAs_AllianceFactSheetInformations(param1);
  param1->writeShort((short)this->guilds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->guilds.size())
  {
    qSharedPointerCast<GuildInsiderFactSheetInformations>(this->guilds[_loc2_])->serializeAs_GuildInsiderFactSheetInformations(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->prisms.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->prisms.size())
  {
    param1->writeShort((short)qSharedPointerCast<PrismSubareaEmptyInfo>(this->prisms[_loc3_])->getTypes().last());
    qSharedPointerCast<PrismSubareaEmptyInfo>(this->prisms[_loc3_])->serialize(param1);
    _loc3_++;
  }
}

void AllianceInsiderInfoMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInsiderInfoMessage(param1);
}

void AllianceInsiderInfoMessage::deserializeAs_AllianceInsiderInfoMessage(Reader *param1)
{
  QSharedPointer<GuildInsiderFactSheetInformations> _loc6_ ;
  uint _loc7_ = 0;
  QSharedPointer<PrismSubareaEmptyInfo> _loc8_ ;
  this->allianceInfos = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
  this->allianceInfos->deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = QSharedPointer<GuildInsiderFactSheetInformations>(new GuildInsiderFactSheetInformations() );
    _loc6_->deserialize(param1);
    this->guilds.append(_loc6_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readUShort();
    _loc8_ = qSharedPointerCast<PrismSubareaEmptyInfo>(ClassManagerSingleton::get()->getClass(_loc7_));
    _loc8_->deserialize(param1);
    this->prisms.append(_loc8_);
    _loc5_++;
  }
}

AllianceInsiderInfoMessage::AllianceInsiderInfoMessage()
{
  m_type = MessageEnum::ALLIANCEINSIDERINFOMESSAGE;
}

