#include "GuildInformationsMemberUpdateMessage.h"

void GuildInformationsMemberUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInformationsMemberUpdateMessage(param1);
}

void GuildInformationsMemberUpdateMessage::serializeAs_GuildInformationsMemberUpdateMessage(Writer *param1)
{
  this->member->serializeAs_GuildMember(param1);
}

void GuildInformationsMemberUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInformationsMemberUpdateMessage(param1);
}

void GuildInformationsMemberUpdateMessage::deserializeAs_GuildInformationsMemberUpdateMessage(Reader *param1)
{
  this->member = QSharedPointer<GuildMember>(new GuildMember() );
  this->member->deserialize(param1);
}

GuildInformationsMemberUpdateMessage::GuildInformationsMemberUpdateMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSMEMBERUPDATEMESSAGE;
}

