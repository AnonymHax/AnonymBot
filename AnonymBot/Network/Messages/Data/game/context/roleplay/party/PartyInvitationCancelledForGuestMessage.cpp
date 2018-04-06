#include "PartyInvitationCancelledForGuestMessage.h"

void PartyInvitationCancelledForGuestMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationCancelledForGuestMessage(param1);
}

void PartyInvitationCancelledForGuestMessage::serializeAs_PartyInvitationCancelledForGuestMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->cancelerId < 0 || this->cancelerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationCancelledForGuestMessage -"<<"Forbidden value (" << this->cancelerId << ") on element cancelerId.";
  }
  else
  {
    param1->writeVarLong((double)this->cancelerId);
    return;
  }
}

void PartyInvitationCancelledForGuestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationCancelledForGuestMessage(param1);
}

void PartyInvitationCancelledForGuestMessage::deserializeAs_PartyInvitationCancelledForGuestMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->cancelerId = param1->readVarUhLong();
  if(this->cancelerId < 0 || this->cancelerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationCancelledForGuestMessage -"<<"Forbidden value (" << this->cancelerId << ") on element of PartyInvitationCancelledForGuestMessage.cancelerId.";
  }
  else
  {
    return;
  }
}

PartyInvitationCancelledForGuestMessage::PartyInvitationCancelledForGuestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONCANCELLEDFORGUESTMESSAGE;
}

