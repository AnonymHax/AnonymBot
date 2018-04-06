#include "GuildModificationValidMessage.h"

void GuildModificationValidMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildModificationValidMessage(param1);
}

void GuildModificationValidMessage::serializeAs_GuildModificationValidMessage(Writer *param1)
{
  param1->writeUTF(this->guildName);
  this->guildEmblem.serializeAs_GuildEmblem(param1);
}

void GuildModificationValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildModificationValidMessage(param1);
}

void GuildModificationValidMessage::deserializeAs_GuildModificationValidMessage(Reader *param1)
{
  this->guildName = param1->readUTF();
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(param1);
}

GuildModificationValidMessage::GuildModificationValidMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONVALIDMESSAGE;
}

