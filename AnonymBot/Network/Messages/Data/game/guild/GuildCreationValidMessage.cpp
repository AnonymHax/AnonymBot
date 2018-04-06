#include "GuildCreationValidMessage.h"

void GuildCreationValidMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildCreationValidMessage(param1);
}

void GuildCreationValidMessage::serializeAs_GuildCreationValidMessage(Writer *param1)
{
  param1->writeUTF(this->guildName);
  this->guildEmblem.serializeAs_GuildEmblem(param1);
}

void GuildCreationValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildCreationValidMessage(param1);
}

void GuildCreationValidMessage::deserializeAs_GuildCreationValidMessage(Reader *param1)
{
  this->guildName = param1->readUTF();
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(param1);
}

GuildCreationValidMessage::GuildCreationValidMessage()
{
  m_type = MessageEnum::GUILDCREATIONVALIDMESSAGE;
}

