#include "CharacterMinimalPlusLookInformations.h"

void CharacterMinimalPlusLookInformations::serialize(Writer *param1)
{
  this->serializeAs_CharacterMinimalPlusLookInformations(param1);
}

void CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(Writer *param1)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(param1);
  this->entityLook->serializeAs_EntityLook(param1);
}

void CharacterMinimalPlusLookInformations::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterMinimalPlusLookInformations(param1);
}

void CharacterMinimalPlusLookInformations::deserializeAs_CharacterMinimalPlusLookInformations(Reader *param1)
{
  CharacterMinimalInformations::deserialize(param1);
  this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->entityLook->deserialize(param1);
}

CharacterMinimalPlusLookInformations::CharacterMinimalPlusLookInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALPLUSLOOKINFORMATIONS;
}

bool CharacterMinimalPlusLookInformations::operator==(const CharacterMinimalPlusLookInformations &compared)
{
  if(entityLook == compared.entityLook)
  return true;
  
  return false;
}

