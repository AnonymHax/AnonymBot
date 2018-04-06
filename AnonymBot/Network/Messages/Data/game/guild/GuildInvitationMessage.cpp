#include "GuildInvitationMessage.h"

void GuildInvitationMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInvitationMessage(param1);
}

void GuildInvitationMessage::serializeAs_GuildInvitationMessage(Writer *param1)
{
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeVarLong((double)this->targetId);
    return;
  }
}

void GuildInvitationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInvitationMessage(param1);
}

void GuildInvitationMessage::deserializeAs_GuildInvitationMessage(Reader *param1)
{
  this->targetId = param1->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GuildInvitationMessage.targetId.";
  }
  else
  {
    return;
  }
}

GuildInvitationMessage::GuildInvitationMessage()
{
  m_type = MessageEnum::GUILDINVITATIONMESSAGE;
}

