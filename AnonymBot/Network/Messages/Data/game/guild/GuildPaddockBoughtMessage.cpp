#include "GuildPaddockBoughtMessage.h"

void GuildPaddockBoughtMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildPaddockBoughtMessage(param1);
}

void GuildPaddockBoughtMessage::serializeAs_GuildPaddockBoughtMessage(Writer *param1)
{
  this->paddockInfo->serializeAs_PaddockContentInformations(param1);
}

void GuildPaddockBoughtMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildPaddockBoughtMessage(param1);
}

void GuildPaddockBoughtMessage::deserializeAs_GuildPaddockBoughtMessage(Reader *param1)
{
  this->paddockInfo = QSharedPointer<PaddockContentInformations>(new PaddockContentInformations() );
  this->paddockInfo->deserialize(param1);
}

GuildPaddockBoughtMessage::GuildPaddockBoughtMessage()
{
  m_type = MessageEnum::GUILDPADDOCKBOUGHTMESSAGE;
}

