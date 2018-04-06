#include "PartyInvitationArenaRequestMessage.h"

void PartyInvitationArenaRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationArenaRequestMessage(param1);
}

void PartyInvitationArenaRequestMessage::serializeAs_PartyInvitationArenaRequestMessage(Writer *param1)
{
  PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(param1);
}

void PartyInvitationArenaRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationArenaRequestMessage(param1);
}

void PartyInvitationArenaRequestMessage::deserializeAs_PartyInvitationArenaRequestMessage(Reader *param1)
{
  PartyInvitationRequestMessage::deserialize(param1);
}

PartyInvitationArenaRequestMessage::PartyInvitationArenaRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONARENAREQUESTMESSAGE;
}

