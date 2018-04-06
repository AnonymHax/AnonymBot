#include "AllianceInvitationStateRecruterMessage.h"

void AllianceInvitationStateRecruterMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceInvitationStateRecruterMessage(param1);
}

void AllianceInvitationStateRecruterMessage::serializeAs_AllianceInvitationStateRecruterMessage(Writer *param1)
{
  param1->writeUTF(this->recrutedName);
  param1->writeByte(this->invitationState);
}

void AllianceInvitationStateRecruterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInvitationStateRecruterMessage(param1);
}

void AllianceInvitationStateRecruterMessage::deserializeAs_AllianceInvitationStateRecruterMessage(Reader *param1)
{
  this->recrutedName = param1->readUTF();
  this->invitationState = param1->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - AllianceInvitationStateRecruterMessage -"<<"Forbidden value (" << this->invitationState << ") on element of AllianceInvitationStateRecruterMessage.invitationState.";
  }
  else
  {
    return;
  }
}

AllianceInvitationStateRecruterMessage::AllianceInvitationStateRecruterMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONSTATERECRUTERMESSAGE;
}

