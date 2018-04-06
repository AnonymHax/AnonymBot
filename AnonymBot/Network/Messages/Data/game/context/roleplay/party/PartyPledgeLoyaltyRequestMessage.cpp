#include "PartyPledgeLoyaltyRequestMessage.h"

void PartyPledgeLoyaltyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyPledgeLoyaltyRequestMessage(param1);
}

void PartyPledgeLoyaltyRequestMessage::serializeAs_PartyPledgeLoyaltyRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeBool(this->loyal);
}

void PartyPledgeLoyaltyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyPledgeLoyaltyRequestMessage(param1);
}

void PartyPledgeLoyaltyRequestMessage::deserializeAs_PartyPledgeLoyaltyRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->loyal = param1->readBool();
}

PartyPledgeLoyaltyRequestMessage::PartyPledgeLoyaltyRequestMessage()
{
  m_type = MessageEnum::PARTYPLEDGELOYALTYREQUESTMESSAGE;
}

