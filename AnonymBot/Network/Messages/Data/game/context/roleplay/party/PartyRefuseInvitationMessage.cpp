#include "PartyRefuseInvitationMessage.h"

void PartyRefuseInvitationMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyRefuseInvitationMessage(param1);
}

void PartyRefuseInvitationMessage::serializeAs_PartyRefuseInvitationMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyRefuseInvitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyRefuseInvitationMessage(param1);
}

void PartyRefuseInvitationMessage::deserializeAs_PartyRefuseInvitationMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyRefuseInvitationMessage::PartyRefuseInvitationMessage()
{
  m_type = MessageEnum::PARTYREFUSEINVITATIONMESSAGE;
}

