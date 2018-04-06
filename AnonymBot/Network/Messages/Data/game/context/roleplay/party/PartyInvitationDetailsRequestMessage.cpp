#include "PartyInvitationDetailsRequestMessage.h"

void PartyInvitationDetailsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationDetailsRequestMessage(param1);
}

void PartyInvitationDetailsRequestMessage::serializeAs_PartyInvitationDetailsRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyInvitationDetailsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationDetailsRequestMessage(param1);
}

void PartyInvitationDetailsRequestMessage::deserializeAs_PartyInvitationDetailsRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyInvitationDetailsRequestMessage::PartyInvitationDetailsRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDETAILSREQUESTMESSAGE;
}

