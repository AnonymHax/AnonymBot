#include "GuildInformations.h"

void GuildInformations::serialize(Writer *param1)
{
  this->serializeAs_GuildInformations(param1);
}

void GuildInformations::serializeAs_GuildInformations(Writer *param1)
{
  BasicGuildInformations::serializeAs_BasicGuildInformations(param1);
  this->guildEmblem.serializeAs_GuildEmblem(param1);
}

void GuildInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInformations(param1);
}

void GuildInformations::deserializeAs_GuildInformations(Reader *param1)
{
  BasicGuildInformations::deserialize(param1);
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(param1);
}

GuildInformations::GuildInformations()
{
  m_types<<ClassEnum::GUILDINFORMATIONS;
}

bool GuildInformations::operator==(const GuildInformations &compared)
{
  if(guildEmblem == compared.guildEmblem)
  return true;
  
  return false;
}

