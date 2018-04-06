#ifndef CHARACTERBASICMINIMALINFORMATIONS_H
#define CHARACTERBASICMINIMALINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/AbstractCharacterInformation.h"

class CharacterBasicMinimalInformations : public AbstractCharacterInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterBasicMinimalInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterBasicMinimalInformations(Reader *param1);
  CharacterBasicMinimalInformations();
  bool operator==(const CharacterBasicMinimalInformations &compared);

  QString name;
};

#endif // CHARACTERBASICMINIMALINFORMATIONS_H