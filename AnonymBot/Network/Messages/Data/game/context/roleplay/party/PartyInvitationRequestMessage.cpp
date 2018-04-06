#include "PartyInvitationRequestMessage.h"

void PartyInvitationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationRequestMessage(param1);
}

void PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(Writer *param1)
{
  param1->writeUTF(this->name);
}

void PartyInvitationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationRequestMessage(param1);
}

void PartyInvitationRequestMessage::deserializeAs_PartyInvitationRequestMessage(Reader *param1)
{
  this->name = param1->readUTF();
}

PartyInvitationRequestMessage::PartyInvitationRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONREQUESTMESSAGE;
}

