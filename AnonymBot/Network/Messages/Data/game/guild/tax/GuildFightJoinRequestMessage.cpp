#include "GuildFightJoinRequestMessage.h"

void GuildFightJoinRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightJoinRequestMessage(param1);
}

void GuildFightJoinRequestMessage::serializeAs_GuildFightJoinRequestMessage(Writer *param1)
{
  param1->writeInt((int)this->taxCollectorId);
}

void GuildFightJoinRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightJoinRequestMessage(param1);
}

void GuildFightJoinRequestMessage::deserializeAs_GuildFightJoinRequestMessage(Reader *param1)
{
  this->taxCollectorId = param1->readInt();
}

GuildFightJoinRequestMessage::GuildFightJoinRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTJOINREQUESTMESSAGE;
}

