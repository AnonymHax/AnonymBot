#include "GuildMotdMessage.h"

void GuildMotdMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMotdMessage(param1);
}

void GuildMotdMessage::serializeAs_GuildMotdMessage(Writer *param1)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(param1);
}

void GuildMotdMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMotdMessage(param1);
}

void GuildMotdMessage::deserializeAs_GuildMotdMessage(Reader *param1)
{
  SocialNoticeMessage::deserialize(param1);
}

GuildMotdMessage::GuildMotdMessage()
{
  m_type = MessageEnum::GUILDMOTDMESSAGE;
}

