#ifndef CHARACTERHARDCOREOREPICINFORMATIONS_H
#define CHARACTERHARDCOREOREPICINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class CharacterHardcoreOrEpicInformations : public CharacterBaseInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterHardcoreOrEpicInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterHardcoreOrEpicInformations(Reader *param1);
  CharacterHardcoreOrEpicInformations();
  bool operator==(const CharacterHardcoreOrEpicInformations &compared);

  uint deathState;
  uint deathCount;
  uint deathMaxLevel;
};

#endif // CHARACTERHARDCOREOREPICINFORMATIONS_H