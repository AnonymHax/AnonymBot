#include "GuildInvitationStateRecruterMessage.h"

void GuildInvitationStateRecruterMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInvitationStateRecruterMessage(param1);
}

void GuildInvitationStateRecruterMessage::serializeAs_GuildInvitationStateRecruterMessage(Writer *param1)
{
  param1->writeUTF(this->recrutedName);
  param1->writeByte(this->invitationState);
}

void GuildInvitationStateRecruterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInvitationStateRecruterMessage(param1);
}

void GuildInvitationStateRecruterMessage::deserializeAs_GuildInvitationStateRecruterMessage(Reader *param1)
{
  this->recrutedName = param1->readUTF();
  this->invitationState = param1->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - GuildInvitationStateRecruterMessage -"<<"Forbidden value (" << this->invitationState << ") on element of GuildInvitationStateRecruterMessage.invitationState.";
  }
  else
  {
    return;
  }
}

GuildInvitationStateRecruterMessage::GuildInvitationStateRecruterMessage()
{
  m_type = MessageEnum::GUILDINVITATIONSTATERECRUTERMESSAGE;
}

