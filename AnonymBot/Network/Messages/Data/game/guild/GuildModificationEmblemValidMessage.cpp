#include "GuildModificationEmblemValidMessage.h"

void GuildModificationEmblemValidMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildModificationEmblemValidMessage(param1);
}

void GuildModificationEmblemValidMessage::serializeAs_GuildModificationEmblemValidMessage(Writer *param1)
{
  this->guildEmblem.serializeAs_GuildEmblem(param1);
}

void GuildModificationEmblemValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildModificationEmblemValidMessage(param1);
}

void GuildModificationEmblemValidMessage::deserializeAs_GuildModificationEmblemValidMessage(Reader *param1)
{
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(param1);
}

GuildModificationEmblemValidMessage::GuildModificationEmblemValidMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONEMBLEMVALIDMESSAGE;
}

