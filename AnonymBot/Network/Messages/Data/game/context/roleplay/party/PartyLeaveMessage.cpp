#include "PartyLeaveMessage.h"

void PartyLeaveMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyLeaveMessage(param1);
}

void PartyLeaveMessage::serializeAs_PartyLeaveMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyLeaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyLeaveMessage(param1);
}

void PartyLeaveMessage::deserializeAs_PartyLeaveMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyLeaveMessage::PartyLeaveMessage()
{
  m_type = MessageEnum::PARTYLEAVEMESSAGE;
}

