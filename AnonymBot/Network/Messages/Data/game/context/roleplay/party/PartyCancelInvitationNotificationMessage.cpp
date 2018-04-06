#include "PartyCancelInvitationNotificationMessage.h"

void PartyCancelInvitationNotificationMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyCancelInvitationNotificationMessage(param1);
}

void PartyCancelInvitationNotificationMessage::serializeAs_PartyCancelInvitationNotificationMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  if(this->cancelerId < 0 || this->cancelerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->cancelerId << ") on element cancelerId.";
  }
  else
  {
    param1->writeVarLong((double)this->cancelerId);
    if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
    }
    else
    {
      param1->writeVarLong((double)this->guestId);
      return;
    }
  }
}

void PartyCancelInvitationNotificationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyCancelInvitationNotificationMessage(param1);
}

void PartyCancelInvitationNotificationMessage::deserializeAs_PartyCancelInvitationNotificationMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  this->cancelerId = param1->readVarUhLong();
  if(this->cancelerId < 0 || this->cancelerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->cancelerId << ") on element of PartyCancelInvitationNotificationMessage.cancelerId.";
  }
  else
  {
    this->guestId = param1->readVarUhLong();
    if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element of PartyCancelInvitationNotificationMessage.guestId.";
    }
    else
    {
      return;
    }
  }
}

PartyCancelInvitationNotificationMessage::PartyCancelInvitationNotificationMessage()
{
  m_type = MessageEnum::PARTYCANCELINVITATIONNOTIFICATIONMESSAGE;
}

