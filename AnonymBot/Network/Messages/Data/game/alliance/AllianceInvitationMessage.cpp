#include "AllianceInvitationMessage.h"

void AllianceInvitationMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceInvitationMessage(param1);
}

void AllianceInvitationMessage::serializeAs_AllianceInvitationMessage(Writer *param1)
{
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeVarLong((double)this->targetId);
    return;
  }
}

void AllianceInvitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInvitationMessage(param1);
}

void AllianceInvitationMessage::deserializeAs_AllianceInvitationMessage(Reader *param1)
{
  this->targetId = param1->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element of AllianceInvitationMessage.targetId.";
  }
  else
  {
    return;
  }
}

AllianceInvitationMessage::AllianceInvitationMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONMESSAGE;
}

