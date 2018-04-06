#include "GuildInvitationStateRecrutedMessage.h"

void GuildInvitationStateRecrutedMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInvitationStateRecrutedMessage(param1);
}

void GuildInvitationStateRecrutedMessage::serializeAs_GuildInvitationStateRecrutedMessage(Writer *param1)
{
  param1->writeByte(this->invitationState);
}

void GuildInvitationStateRecrutedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInvitationStateRecrutedMessage(param1);
}

void GuildInvitationStateRecrutedMessage::deserializeAs_GuildInvitationStateRecrutedMessage(Reader *param1)
{
  this->invitationState = param1->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - GuildInvitationStateRecrutedMessage -"<<"Forbidden value (" << this->invitationState << ") on element of GuildInvitationStateRecrutedMessage.invitationState.";
  }
  else
  {
    return;
  }
}

GuildInvitationStateRecrutedMessage::GuildInvitationStateRecrutedMessage()
{
  m_type = MessageEnum::GUILDINVITATIONSTATERECRUTEDMESSAGE;
}

