#include "HumanOptionGuild.h"

void HumanOptionGuild::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionGuild(param1);
}

void HumanOptionGuild::serializeAs_HumanOptionGuild(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  this->guildInformations->serializeAs_GuildInformations(param1);
}

void HumanOptionGuild::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionGuild(param1);
}

void HumanOptionGuild::deserializeAs_HumanOptionGuild(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->guildInformations = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformations->deserialize(param1);
}

HumanOptionGuild::HumanOptionGuild()
{
  m_types<<ClassEnum::HUMANOPTIONGUILD;
}

bool HumanOptionGuild::operator==(const HumanOptionGuild &compared)
{
  if(guildInformations == compared.guildInformations)
  return true;
  
  return false;
}

