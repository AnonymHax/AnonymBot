#include "PartyDeletedMessage.h"

void PartyDeletedMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyDeletedMessage(param1);
}

void PartyDeletedMessage::serializeAs_PartyDeletedMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyDeletedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyDeletedMessage(param1);
}

void PartyDeletedMessage::deserializeAs_PartyDeletedMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyDeletedMessage::PartyDeletedMessage()
{
  m_type = MessageEnum::PARTYDELETEDMESSAGE;
}

