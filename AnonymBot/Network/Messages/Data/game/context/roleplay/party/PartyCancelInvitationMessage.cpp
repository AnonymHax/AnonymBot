#include "PartyCancelInvitationMessage.h"

void PartyCancelInvitationMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyCancelInvitationMessage(param1);
}

void PartyCancelInvitationMessage::serializeAs_PartyCancelInvitationMessage(Writer *param1)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(param1);
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  else
  {
    param1->writeVarLong((double)this->guestId);
    return;
  }
}

void PartyCancelInvitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyCancelInvitationMessage(param1);
}

void PartyCancelInvitationMessage::deserializeAs_PartyCancelInvitationMessage(Reader *param1)
{
  AbstractPartyMessage::deserialize(param1);
  this->guestId = param1->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationMessage -"<<"Forbidden value (" << this->guestId << ") on element of PartyCancelInvitationMessage.guestId.";
  }
  else
  {
    return;
  }
}

PartyCancelInvitationMessage::PartyCancelInvitationMessage()
{
  m_type = MessageEnum::PARTYCANCELINVITATIONMESSAGE;
}

