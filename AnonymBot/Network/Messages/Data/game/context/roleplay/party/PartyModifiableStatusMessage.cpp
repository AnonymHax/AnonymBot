#include "PartyModifiableStatusMessage.h"

void PartyModifiableStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyModifiableStatusMessage(param1);
}

void PartyModifiableStatusMessage::serializeAs_PartyModifiableStatusMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeBool(this->enabled);
}

void PartyModifiableStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyModifiableStatusMessage(param1);
}

void PartyModifiableStatusMessage::deserializeAs_PartyModifiableStatusMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->enabled = param1->readBool();
}

PartyModifiableStatusMessage::PartyModifiableStatusMessage()
{
  m_type = MessageEnum::PARTYMODIFIABLESTATUSMESSAGE;
}

