#include "PartyNameUpdateMessage.h"

void PartyNameUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyNameUpdateMessage(param1);
}

void PartyNameUpdateMessage::serializeAs_PartyNameUpdateMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  param1->writeUTF(this->partyName);
}

void PartyNameUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyNameUpdateMessage(param1);
}

void PartyNameUpdateMessage::deserializeAs_PartyNameUpdateMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->partyName = param1->readUTF();
}

PartyNameUpdateMessage::PartyNameUpdateMessage()
{
  m_type = MessageEnum::PARTYNAMEUPDATEMESSAGE;
}

