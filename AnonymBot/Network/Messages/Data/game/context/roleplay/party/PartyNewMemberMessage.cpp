#include "PartyNewMemberMessage.h"

void PartyNewMemberMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyNewMemberMessage(param1);
}

void PartyNewMemberMessage::serializeAs_PartyNewMemberMessage(Writer *param1)
{
  PartyUpdateMessage::serializeAs_PartyUpdateMessage(param1);
}

void PartyNewMemberMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyNewMemberMessage(param1);
}

void PartyNewMemberMessage::deserializeAs_PartyNewMemberMessage(Reader *param1)
{
  PartyUpdateMessage::deserialize(param1);
}

PartyNewMemberMessage::PartyNewMemberMessage()
{
  m_type = MessageEnum::PARTYNEWMEMBERMESSAGE;
}

