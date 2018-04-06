#include "GuildMotdSetRequestMessage.h"

void GuildMotdSetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMotdSetRequestMessage(param1);
}

void GuildMotdSetRequestMessage::serializeAs_GuildMotdSetRequestMessage(Writer *param1)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(param1);
  param1->writeUTF(this->content);
}

void GuildMotdSetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMotdSetRequestMessage(param1);
}

void GuildMotdSetRequestMessage::deserializeAs_GuildMotdSetRequestMessage(Reader *param1)
{
  SocialNoticeSetRequestMessage::deserialize(param1);
  this->content = param1->readUTF();
}

GuildMotdSetRequestMessage::GuildMotdSetRequestMessage()
{
  m_type = MessageEnum::GUILDMOTDSETREQUESTMESSAGE;
}

