#include "CharacterMinimalGuildInformations.h"

void CharacterMinimalGuildInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterMinimalGuildInformations(param1);
}

void CharacterMinimalGuildInformations::serializeAs_CharacterMinimalGuildInformations(Writer *param1)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(param1);
  this->guild->serializeAs_BasicGuildInformations(param1);
}

void CharacterMinimalGuildInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterMinimalGuildInformations(param1);
}

void CharacterMinimalGuildInformations::deserializeAs_CharacterMinimalGuildInformations(Reader *param1)
{
  CharacterMinimalPlusLookInformations::deserialize(param1);
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserialize(param1);
}

CharacterMinimalGuildInformations::CharacterMinimalGuildInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALGUILDINFORMATIONS;
}

bool CharacterMinimalGuildInformations::operator==(const CharacterMinimalGuildInformations &compared)
{
  if(guild == compared.guild)
  return true;
  
  return false;
}

