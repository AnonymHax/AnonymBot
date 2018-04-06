#ifndef CHARACTERTOREMODELINFORMATIONS_H
#define CHARACTERTOREMODELINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/choice/CharacterRemodelingInformation.h"

class CharacterToRemodelInformations : public CharacterRemodelingInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterToRemodelInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterToRemodelInformations(Reader *param1);
  CharacterToRemodelInformations();
  bool operator==(const CharacterToRemodelInformations &compared);

  uint possibleChangeMask;
  uint mandatoryChangeMask;
};

#endif // CHARACTERTOREMODELINFORMATIONS_H