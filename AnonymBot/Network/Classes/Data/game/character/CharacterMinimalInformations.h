#ifndef CHARACTERMINIMALINFORMATIONS_H
#define CHARACTERMINIMALINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/CharacterBasicMinimalInformations.h"

class CharacterMinimalInformations : public CharacterBasicMinimalInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterMinimalInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterMinimalInformations(Reader *param1);
  CharacterMinimalInformations();
  bool operator==(const CharacterMinimalInformations &compared);

  uint level;
};

#endif // CHARACTERMINIMALINFORMATIONS_H