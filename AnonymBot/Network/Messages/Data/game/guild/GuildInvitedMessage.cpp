#include "GuildInvitedMessage.h"

void GuildInvitedMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInvitedMessage(param1);
}

void GuildInvitedMessage::serializeAs_GuildInvitedMessage(Writer *param1)
{
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element recruterId.";
  }
  else
  {
    param1->writeVarLong((double)this->recruterId);
    param1->writeUTF(this->recruterName);
    this->guildInfo->serializeAs_BasicGuildInformations(param1);
    return;
  }
}

void GuildInvitedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInvitedMessage(param1);
}

void GuildInvitedMessage::deserializeAs_GuildInvitedMessage(Reader *param1)
{
  this->recruterId = param1->readVarUhLong();
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element of GuildInvitedMessage.recruterId.";
  }
  else
  {
    this->recruterName = param1->readUTF();
    this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
    this->guildInfo->deserialize(param1);
    return;
  }
}

GuildInvitedMessage::GuildInvitedMessage()
{
  m_type = MessageEnum::GUILDINVITEDMESSAGE;
}

