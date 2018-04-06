#include "PartyLocateMembersRequestMessage.h"

void PartyLocateMembersRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyLocateMembersRequestMessage(param1);
}

void PartyLocateMembersRequestMessage::serializeAs_PartyLocateMembersRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyLocateMembersRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyLocateMembersRequestMessage(param1);
}

void PartyLocateMembersRequestMessage::deserializeAs_PartyLocateMembersRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyLocateMembersRequestMessage::PartyLocateMembersRequestMessage()
{
  m_type = MessageEnum::PARTYLOCATEMEMBERSREQUESTMESSAGE;
}

