#include "PartyLeaveRequestMessage.h"

void PartyLeaveRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyLeaveRequestMessage(param1);
}

void PartyLeaveRequestMessage::serializeAs_PartyLeaveRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
}

void PartyLeaveRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyLeaveRequestMessage(param1);
}

void PartyLeaveRequestMessage::deserializeAs_PartyLeaveRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
}

PartyLeaveRequestMessage::PartyLeaveRequestMessage()
{
  m_type = MessageEnum::PARTYLEAVEREQUESTMESSAGE;
}

