#include "UpdateMountBoostMessage.h"

void UpdateMountBoostMessage::serialize(Writer *param1)
{
  this->serializeAs_UpdateMountBoostMessage(param1);
}

void UpdateMountBoostMessage::serializeAs_UpdateMountBoostMessage(Writer *param1)
{
  param1->writeVarInt((int)this->rideId);
  param1->writeShort((short)this->boostToUpdateList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->boostToUpdateList.size())
  {
    param1->writeShort((short)qSharedPointerCast<UpdateMountBoost>(this->boostToUpdateList[_loc2_])->getTypes().last());
    qSharedPointerCast<UpdateMountBoost>(this->boostToUpdateList[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void UpdateMountBoostMessage::deserialize(Reader *param1)
{
  this->deserializeAs_UpdateMountBoostMessage(param1);
}

void UpdateMountBoostMessage::deserializeAs_UpdateMountBoostMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<UpdateMountBoost> _loc5_ ;
  this->rideId = param1->readVarInt();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<UpdateMountBoost>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->boostToUpdateList.append(_loc5_);
    _loc3_++;
  }
}

UpdateMountBoostMessage::UpdateMountBoostMessage()
{
  m_type = MessageEnum::UPDATEMOUNTBOOSTMESSAGE;
}

