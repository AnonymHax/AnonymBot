#include "GuildMemberSetWarnOnConnectionMessage.h"

void GuildMemberSetWarnOnConnectionMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMemberSetWarnOnConnectionMessage(param1);
}

void GuildMemberSetWarnOnConnectionMessage::serializeAs_GuildMemberSetWarnOnConnectionMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void GuildMemberSetWarnOnConnectionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMemberSetWarnOnConnectionMessage(param1);
}

void GuildMemberSetWarnOnConnectionMessage::deserializeAs_GuildMemberSetWarnOnConnectionMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

GuildMemberSetWarnOnConnectionMessage::GuildMemberSetWarnOnConnectionMessage()
{
  m_type = MessageEnum::GUILDMEMBERSETWARNONCONNECTIONMESSAGE;
}

