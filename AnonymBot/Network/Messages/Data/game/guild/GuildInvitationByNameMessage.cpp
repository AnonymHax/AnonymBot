#include "GuildInvitationByNameMessage.h"

void GuildInvitationByNameMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInvitationByNameMessage(param1);
}

void GuildInvitationByNameMessage::serializeAs_GuildInvitationByNameMessage(Writer *param1)
{
  param1->writeUTF(this->name);
}

void GuildInvitationByNameMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInvitationByNameMessage(param1);
}

void GuildInvitationByNameMessage::deserializeAs_GuildInvitationByNameMessage(Reader *param1)
{
  this->name = param1->readUTF();
}

GuildInvitationByNameMessage::GuildInvitationByNameMessage()
{
  m_type = MessageEnum::GUILDINVITATIONBYNAMEMESSAGE;
}

