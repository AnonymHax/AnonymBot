#include "GuildMotdSetErrorMessage.h"

void GuildMotdSetErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMotdSetErrorMessage(param1);
}

void GuildMotdSetErrorMessage::serializeAs_GuildMotdSetErrorMessage(Writer *param1)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(param1);
}

void GuildMotdSetErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMotdSetErrorMessage(param1);
}

void GuildMotdSetErrorMessage::deserializeAs_GuildMotdSetErrorMessage(Reader *param1)
{
  SocialNoticeSetErrorMessage::deserialize(param1);
}

GuildMotdSetErrorMessage::GuildMotdSetErrorMessage()
{
  m_type = MessageEnum::GUILDMOTDSETERRORMESSAGE;
}

