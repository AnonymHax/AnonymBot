#include "GuildMembershipMessage.h"

void GuildMembershipMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMembershipMessage(param1);
}

void GuildMembershipMessage::serializeAs_GuildMembershipMessage(Writer *param1)
{
  GuildJoinedMessage::serializeAs_GuildJoinedMessage(param1);
}

void GuildMembershipMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMembershipMessage(param1);
}

void GuildMembershipMessage::deserializeAs_GuildMembershipMessage(Reader *param1)
{
  GuildJoinedMessage::deserialize(param1);
}

GuildMembershipMessage::GuildMembershipMessage()
{
  m_type = MessageEnum::GUILDMEMBERSHIPMESSAGE;
}

