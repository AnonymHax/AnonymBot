#include "CharacterToRecolorInformation.h"

void CharacterToRecolorInformation::serialize(Writer *param1)
{
  this->serializeAs_CharacterToRecolorInformation(param1);
}

void CharacterToRecolorInformation::serializeAs_CharacterToRecolorInformation(Writer *param1)
{
  AbstractCharacterToRefurbishInformation::serializeAs_AbstractCharacterToRefurbishInformation(param1);
}

void CharacterToRecolorInformation::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterToRecolorInformation(param1);
}

void CharacterToRecolorInformation::deserializeAs_CharacterToRecolorInformation(Reader *param1)
{
  AbstractCharacterToRefurbishInformation::deserialize(param1);
}

CharacterToRecolorInformation::CharacterToRecolorInformation()
{
  m_types<<ClassEnum::CHARACTERTORECOLORINFORMATION;
}

bool CharacterToRecolorInformation::operator==(const CharacterToRecolorInformation &compared)
{
  return true;
}

