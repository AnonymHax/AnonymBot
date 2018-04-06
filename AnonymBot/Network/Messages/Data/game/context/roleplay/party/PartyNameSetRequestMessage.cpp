#include "PartyNameSetRequestMessage.h"

void PartyNameSetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyNameSetRequestMessage(param1);
}

void PartyNameSetRequestMessage::serializeAs_PartyNameSetRequestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeUTF(this->partyName);
}

void PartyNameSetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyNameSetRequestMessage(param1);
}

void PartyNameSetRequestMessage::deserializeAs_PartyNameSetRequestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->partyName = param1->readUTF();
}

PartyNameSetRequestMessage::PartyNameSetRequestMessage()
{
  m_type = MessageEnum::PARTYNAMESETREQUESTMESSAGE;
}

