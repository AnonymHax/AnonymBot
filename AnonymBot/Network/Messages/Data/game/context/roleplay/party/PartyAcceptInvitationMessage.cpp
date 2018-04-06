#include "PartyAcceptInvitationMessage.h"

void PartyAcceptInvitationMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyAcceptInvitationMessage(param1);
}

void PartyAcceptInvitationMessage::serializeAs_PartyAcceptInvitationMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyAcceptInvitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyAcceptInvitationMessage(param1);
}

void PartyAcceptInvitationMessage::deserializeAs_PartyAcceptInvitationMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyAcceptInvitationMessage::PartyAcceptInvitationMessage()
{
  m_type = MessageEnum::PARTYACCEPTINVITATIONMESSAGE;
}

