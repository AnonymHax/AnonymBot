#include "CharacterBaseInformations.h"

void CharacterBaseInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterBaseInformations(param1);
}

void CharacterBaseInformations::serializeAs_CharacterBaseInformations(Writer *param1)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(param1);
  param1->writeByte(this->breed);
  param1->writeBool(this->sex);
}

void CharacterBaseInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterBaseInformations(param1);
}

void CharacterBaseInformations::deserializeAs_CharacterBaseInformations(Reader *param1)
{
  CharacterMinimalPlusLookInformations::deserialize(param1);
  this->breed = param1->readByte();
  this->sex = param1->readBool();
}

CharacterBaseInformations::CharacterBaseInformations()
{
  m_types<<ClassEnum::CHARACTERBASEINFORMATIONS;
}

bool CharacterBaseInformations::operator==(const CharacterBaseInformations &compared)
{
  if(breed == compared.breed)
  if(sex == compared.sex)
  return true;
  
  return false;
}

