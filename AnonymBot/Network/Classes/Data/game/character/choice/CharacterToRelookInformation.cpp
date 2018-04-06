#include "CharacterToRelookInformation.h"

void CharacterToRelookInformation::serialize(Writer *param1)
{
  this->serializeAs_CharacterToRelookInformation(param1);
}

void CharacterToRelookInformation::serializeAs_CharacterToRelookInformation(Writer *param1)
{
  AbstractCharacterToRefurbishInformation::serializeAs_AbstractCharacterToRefurbishInformation(param1);
}

void CharacterToRelookInformation::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterToRelookInformation(param1);
}

void CharacterToRelookInformation::deserializeAs_CharacterToRelookInformation(Reader *param1)
{
  AbstractCharacterToRefurbishInformation::deserialize(param1);
}

CharacterToRelookInformation::CharacterToRelookInformation()
{
  m_types<<ClassEnum::CHARACTERTORELOOKINFORMATION;
}

bool CharacterToRelookInformation::operator==(const CharacterToRelookInformation &compared)
{
  return true;
}

