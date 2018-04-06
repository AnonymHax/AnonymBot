#include "PartyRefuseInvitationNotificationMessage.h"

void PartyRefuseInvitationNotificationMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyRefuseInvitationNotificationMessage(param1);
}

void PartyRefuseInvitationNotificationMessage::serializeAs_PartyRefuseInvitationNotificationMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyRefuseInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  else
  {
    param1->writeVarLong((double)this->guestId);
    return;
  }
}

void PartyRefuseInvitationNotificationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyRefuseInvitationNotificationMessage(param1);
}

void PartyRefuseInvitationNotificationMessage::deserializeAs_PartyRefuseInvitationNotificationMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  this->guestId = param1->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyRefuseInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element of PartyRefuseInvitationNotificationMessage.guestId.";
  }
  else
  {
    return;
  }
}

PartyRefuseInvitationNotificationMessage::PartyRefuseInvitationNotificationMessage()
{
  m_type = MessageEnum::PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE;
}

