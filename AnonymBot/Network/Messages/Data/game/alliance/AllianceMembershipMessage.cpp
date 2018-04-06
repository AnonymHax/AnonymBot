#include "AllianceMembershipMessage.h"

void AllianceMembershipMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceMembershipMessage(param1);
}

void AllianceMembershipMessage::serializeAs_AllianceMembershipMessage(Writer *param1)
{
  AllianceJoinedMessage::serializeAs_AllianceJoinedMessage(param1);
}

void AllianceMembershipMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceMembershipMessage(param1);
}

void AllianceMembershipMessage::deserializeAs_AllianceMembershipMessage(Reader *param1)
{
  AllianceJoinedMessage::deserialize(param1);
}

AllianceMembershipMessage::AllianceMembershipMessage()
{
  m_type = MessageEnum::ALLIANCEMEMBERSHIPMESSAGE;
}

