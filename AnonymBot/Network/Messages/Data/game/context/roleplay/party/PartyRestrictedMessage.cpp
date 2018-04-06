#include "PartyRestrictedMessage.h"

void PartyRestrictedMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyRestrictedMessage(param1);
}

void PartyRestrictedMessage::serializeAs_PartyRestrictedMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeBool(this->restricted);
}

void PartyRestrictedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyRestrictedMessage(param1);
}

void PartyRestrictedMessage::deserializeAs_PartyRestrictedMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->restricted = param1->readBool();
}

PartyRestrictedMessage::PartyRestrictedMessage()
{
  m_type = MessageEnum::PARTYRESTRICTEDMESSAGE;
}

