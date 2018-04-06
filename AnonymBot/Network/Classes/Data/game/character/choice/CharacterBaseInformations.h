#ifndef CHARACTERBASEINFORMATIONS_H
#define CHARACTERBASEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class CharacterBaseInformations : public CharacterMinimalPlusLookInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterBaseInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterBaseInformations(Reader *param1);
  CharacterBaseInformations();
  bool operator==(const CharacterBaseInformations &compared);

  int breed;
  bool sex;
};

#endif // CHARACTERBASEINFORMATIONS_H