#include "CharacterMinimalAllianceInformations.h"

void CharacterMinimalAllianceInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterMinimalAllianceInformations(param1);
}

void CharacterMinimalAllianceInformations::serializeAs_CharacterMinimalAllianceInformations(Writer *param1)
{
  CharacterMinimalGuildInformations::serializeAs_CharacterMinimalGuildInformations(param1);
  this->alliance->serializeAs_BasicAllianceInformations(param1);
}

void CharacterMinimalAllianceInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterMinimalAllianceInformations(param1);
}

void CharacterMinimalAllianceInformations::deserializeAs_CharacterMinimalAllianceInformations(Reader *param1)
{
  CharacterMinimalGuildInformations::deserialize(param1);
  this->alliance = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->alliance->deserialize(param1);
}

CharacterMinimalAllianceInformations::CharacterMinimalAllianceInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALALLIANCEINFORMATIONS;
}

bool CharacterMinimalAllianceInformations::operator==(const CharacterMinimalAllianceInformations &compared)
{
  if(alliance == compared.alliance)
  return true;
  
  return false;
}

