#include "GuildModificationNameValidMessage.h"

void GuildModificationNameValidMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildModificationNameValidMessage(param1);
}

void GuildModificationNameValidMessage::serializeAs_GuildModificationNameValidMessage(Writer *param1)
{
  param1->writeUTF(this->guildName);
}

void GuildModificationNameValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildModificationNameValidMessage(param1);
}

void GuildModificationNameValidMessage::deserializeAs_GuildModificationNameValidMessage(Reader *param1)
{
  this->guildName = param1->readUTF();
}

GuildModificationNameValidMessage::GuildModificationNameValidMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONNAMEVALIDMESSAGE;
}

