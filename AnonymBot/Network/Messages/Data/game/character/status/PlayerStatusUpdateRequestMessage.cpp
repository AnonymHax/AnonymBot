#include "PlayerStatusUpdateRequestMessage.h"

void PlayerStatusUpdateRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PlayerStatusUpdateRequestMessage(param1);
}

void PlayerStatusUpdateRequestMessage::serializeAs_PlayerStatusUpdateRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->status->getTypes().last());
  this->status->serialize(param1);
}

void PlayerStatusUpdateRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PlayerStatusUpdateRequestMessage(param1);
}

void PlayerStatusUpdateRequestMessage::deserializeAs_PlayerStatusUpdateRequestMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->status->deserialize(param1);
}

PlayerStatusUpdateRequestMessage::PlayerStatusUpdateRequestMessage()
{
  m_type = MessageEnum::PLAYERSTATUSUPDATEREQUESTMESSAGE;
}

