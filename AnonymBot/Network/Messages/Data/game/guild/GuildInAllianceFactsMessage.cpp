#include "GuildInAllianceFactsMessage.h"

void GuildInAllianceFactsMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInAllianceFactsMessage(param1);
}

void GuildInAllianceFactsMessage::serializeAs_GuildInAllianceFactsMessage(Writer *param1)
{
  GuildFactsMessage::serializeAs_GuildFactsMessage(param1);
  this->allianceInfos->serializeAs_BasicNamedAllianceInformations(param1);
}

void GuildInAllianceFactsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInAllianceFactsMessage(param1);
}

void GuildInAllianceFactsMessage::deserializeAs_GuildInAllianceFactsMessage(Reader *param1)
{
  GuildFactsMessage::deserialize(param1);
  this->allianceInfos = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfos->deserialize(param1);
}

GuildInAllianceFactsMessage::GuildInAllianceFactsMessage()
{
  m_type = MessageEnum::GUILDINALLIANCEFACTSMESSAGE;
}

