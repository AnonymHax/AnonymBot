#include "GuildMemberWarnOnConnectionStateMessage.h"

void GuildMemberWarnOnConnectionStateMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMemberWarnOnConnectionStateMessage(param1);
}

void GuildMemberWarnOnConnectionStateMessage::serializeAs_GuildMemberWarnOnConnectionStateMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void GuildMemberWarnOnConnectionStateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMemberWarnOnConnectionStateMessage(param1);
}

void GuildMemberWarnOnConnectionStateMessage::deserializeAs_GuildMemberWarnOnConnectionStateMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

GuildMemberWarnOnConnectionStateMessage::GuildMemberWarnOnConnectionStateMessage()
{
  m_type = MessageEnum::GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE;
}

