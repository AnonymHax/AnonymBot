#include "GuildMemberOnlineStatusMessage.h"

void GuildMemberOnlineStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMemberOnlineStatusMessage(param1);
}

void GuildMemberOnlineStatusMessage::serializeAs_GuildMemberOnlineStatusMessage(Writer *param1)
{
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMemberOnlineStatusMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeVarLong((double)this->memberId);
    param1->writeBool(this->online);
    return;
  }
}

void GuildMemberOnlineStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMemberOnlineStatusMessage(param1);
}

void GuildMemberOnlineStatusMessage::deserializeAs_GuildMemberOnlineStatusMessage(Reader *param1)
{
  this->memberId = param1->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMemberOnlineStatusMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildMemberOnlineStatusMessage.memberId.";
  }
  else
  {
    this->online = param1->readBool();
    return;
  }
}

GuildMemberOnlineStatusMessage::GuildMemberOnlineStatusMessage()
{
  m_type = MessageEnum::GUILDMEMBERONLINESTATUSMESSAGE;
}

