#include "CharacterBasicMinimalInformations.h"

void CharacterBasicMinimalInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterBasicMinimalInformations(param1);
}

void CharacterBasicMinimalInformations::serializeAs_CharacterBasicMinimalInformations(Writer *param1)
{
  AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(param1);
  param1->writeUTF(this->name);
}

void CharacterBasicMinimalInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterBasicMinimalInformations(param1);
}

void CharacterBasicMinimalInformations::deserializeAs_CharacterBasicMinimalInformations(Reader *param1)
{
  AbstractCharacterInformation::deserialize(param1);
  this->name = param1->readUTF();
}

CharacterBasicMinimalInformations::CharacterBasicMinimalInformations()
{
  m_types<<ClassEnum::CHARACTERBASICMINIMALINFORMATIONS;
}

bool CharacterBasicMinimalInformations::operator==(const CharacterBasicMinimalInformations &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

