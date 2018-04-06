#include "PartyFollowStatusUpdateMessage.h"

void PartyFollowStatusUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyFollowStatusUpdateMessage(param1);
}

void PartyFollowStatusUpdateMessage::serializeAs_PartyFollowStatusUpdateMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->success);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isFollowed);
  param1->writeByte(_loc2_);
  if(this->followedId < 0 || this->followedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyFollowStatusUpdateMessage -"<<"Forbidden value (" << this->followedId << ") on element followedId.";
  }
  else
  {
    param1->writeVarLong((double)this->followedId);
    return;
  }
}

void PartyFollowStatusUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyFollowStatusUpdateMessage(param1);
}

void PartyFollowStatusUpdateMessage::deserializeAs_PartyFollowStatusUpdateMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  uint _loc2_ = param1->readByte();
  this->success = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->isFollowed = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->followedId = param1->readVarUhLong();
  if(this->followedId < 0 || this->followedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyFollowStatusUpdateMessage -"<<"Forbidden value (" << this->followedId << ") on element of PartyFollowStatusUpdateMessage.followedId.";
  }
  else
  {
    return;
  }
}

PartyFollowStatusUpdateMessage::PartyFollowStatusUpdateMessage()
{
  m_type = MessageEnum::PARTYFOLLOWSTATUSUPDATEMESSAGE;
}

