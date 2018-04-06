#include "GuildFightTakePlaceRequestMessage.h"

void GuildFightTakePlaceRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightTakePlaceRequestMessage(param1);
}

void GuildFightTakePlaceRequestMessage::serializeAs_GuildFightTakePlaceRequestMessage(Writer *param1)
{
  GuildFightJoinRequestMessage::serializeAs_GuildFightJoinRequestMessage(param1);
  param1->writeInt((int)this->replacedCharacterId);
}

void GuildFightTakePlaceRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightTakePlaceRequestMessage(param1);
}

void GuildFightTakePlaceRequestMessage::deserializeAs_GuildFightTakePlaceRequestMessage(Reader *param1)
{
  GuildFightJoinRequestMessage::deserialize(param1);
  this->replacedCharacterId = param1->readInt();
}

GuildFightTakePlaceRequestMessage::GuildFightTakePlaceRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTTAKEPLACEREQUESTMESSAGE;
}

