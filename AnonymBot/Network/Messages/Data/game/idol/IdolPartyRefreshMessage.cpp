#include "IdolPartyRefreshMessage.h"

void IdolPartyRefreshMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolPartyRefreshMessage(param1);
}

void IdolPartyRefreshMessage::serializeAs_IdolPartyRefreshMessage(Writer *param1)
{
  this->partyIdol->serializeAs_PartyIdol(param1);
}

void IdolPartyRefreshMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolPartyRefreshMessage(param1);
}

void IdolPartyRefreshMessage::deserializeAs_IdolPartyRefreshMessage(Reader *param1)
{
  this->partyIdol = QSharedPointer<PartyIdol>(new PartyIdol() );
  this->partyIdol->deserialize(param1);
}

IdolPartyRefreshMessage::IdolPartyRefreshMessage()
{
  m_type = MessageEnum::IDOLPARTYREFRESHMESSAGE;
}

