#include "PartyNewGuestMessage.h"

void PartyNewGuestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyNewGuestMessage(param1);
}

void PartyNewGuestMessage::serializeAs_PartyNewGuestMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  this->guest->serializeAs_PartyGuestInformations(param1);
}

void PartyNewGuestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyNewGuestMessage(param1);
}

void PartyNewGuestMessage::deserializeAs_PartyNewGuestMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  this->guest = QSharedPointer<PartyGuestInformations>(new PartyGuestInformations() );
  this->guest->deserialize(param1);
}

PartyNewGuestMessage::PartyNewGuestMessage()
{
  m_type = MessageEnum::PARTYNEWGUESTMESSAGE;
}

