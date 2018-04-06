#ifndef CHARACTERTORECOLORINFORMATION_H
#define CHARACTERTORECOLORINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/choice/AbstractCharacterToRefurbishInformation.h"

class CharacterToRecolorInformation : public AbstractCharacterToRefurbishInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterToRecolorInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterToRecolorInformation(Reader *param1);
  CharacterToRecolorInformation();
  bool operator==(const CharacterToRecolorInformation &compared);
};

#endif // CHARACTERTORECOLORINFORMATION_H