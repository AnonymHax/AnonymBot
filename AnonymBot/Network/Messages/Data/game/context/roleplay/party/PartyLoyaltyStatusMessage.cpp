#include "PartyLoyaltyStatusMessage.h"

void PartyLoyaltyStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyLoyaltyStatusMessage(param1);
}

void PartyLoyaltyStatusMessage::serializeAs_PartyLoyaltyStatusMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeBool(this->loyal);
}

void PartyLoyaltyStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyLoyaltyStatusMessage(param1);
}

void PartyLoyaltyStatusMessage::deserializeAs_PartyLoyaltyStatusMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->loyal = param1->readBool();
}

PartyLoyaltyStatusMessage::PartyLoyaltyStatusMessage()
{
  m_type = MessageEnum::PARTYLOYALTYSTATUSMESSAGE;
}

