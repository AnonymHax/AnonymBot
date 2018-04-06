#include "PartyFollowThisMemberRequestMessage.h"

void PartyFollowThisMemberRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyFollowThisMemberRequestMessage(param1);
}

void PartyFollowThisMemberRequestMessage::serializeAs_PartyFollowThisMemberRequestMessage(Writer *param1)
{
  PartyFollowMemberRequestMessage::serializeAs_PartyFollowMemberRequestMessage(param1);
  param1->writeBool(this->enabled);
}

void PartyFollowThisMemberRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyFollowThisMemberRequestMessage(param1);
}

void PartyFollowThisMemberRequestMessage::deserializeAs_PartyFollowThisMemberRequestMessage(Reader *param1)
{
  PartyFollowMemberRequestMessage::deserialize(param1);
  this->enabled = param1->readBool();
}

PartyFollowThisMemberRequestMessage::PartyFollowThisMemberRequestMessage()
{
  m_type = MessageEnum::PARTYFOLLOWTHISMEMBERREQUESTMESSAGE;
}

