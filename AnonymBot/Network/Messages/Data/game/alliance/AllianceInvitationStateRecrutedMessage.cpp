#include "AllianceInvitationStateRecrutedMessage.h"

void AllianceInvitationStateRecrutedMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceInvitationStateRecrutedMessage(param1);
}

void AllianceInvitationStateRecrutedMessage::serializeAs_AllianceInvitationStateRecrutedMessage(Writer *param1)
{
  param1->writeByte(this->invitationState);
}

void AllianceInvitationStateRecrutedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInvitationStateRecrutedMessage(param1);
}

void AllianceInvitationStateRecrutedMessage::deserializeAs_AllianceInvitationStateRecrutedMessage(Reader *param1)
{
  this->invitationState = param1->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - AllianceInvitationStateRecrutedMessage -"<<"Forbidden value (" << this->invitationState << ") on element of AllianceInvitationStateRecrutedMessage.invitationState.";
  }
  else
  {
    return;
  }
}

AllianceInvitationStateRecrutedMessage::AllianceInvitationStateRecrutedMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONSTATERECRUTEDMESSAGE;
}

