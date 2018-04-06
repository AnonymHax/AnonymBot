#include "GuildPaddockRemovedMessage.h"

void GuildPaddockRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildPaddockRemovedMessage(param1);
}

void GuildPaddockRemovedMessage::serializeAs_GuildPaddockRemovedMessage(Writer *param1)
{
  param1->writeInt((int)this->paddockId);
}

void GuildPaddockRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildPaddockRemovedMessage(param1);
}

void GuildPaddockRemovedMessage::deserializeAs_GuildPaddockRemovedMessage(Reader *param1)
{
  this->paddockId = param1->readInt();
}

GuildPaddockRemovedMessage::GuildPaddockRemovedMessage()
{
  m_type = MessageEnum::GUILDPADDOCKREMOVEDMESSAGE;
}

