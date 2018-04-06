#include "GuildPaddockTeleportRequestMessage.h"

void GuildPaddockTeleportRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildPaddockTeleportRequestMessage(param1);
}

void GuildPaddockTeleportRequestMessage::serializeAs_GuildPaddockTeleportRequestMessage(Writer *param1)
{
  param1->writeInt((int)this->paddockId);
}

void GuildPaddockTeleportRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildPaddockTeleportRequestMessage(param1);
}

void GuildPaddockTeleportRequestMessage::deserializeAs_GuildPaddockTeleportRequestMessage(Reader *param1)
{
  this->paddockId = param1->readInt();
}

GuildPaddockTeleportRequestMessage::GuildPaddockTeleportRequestMessage()
{
  m_type = MessageEnum::GUILDPADDOCKTELEPORTREQUESTMESSAGE;
}

