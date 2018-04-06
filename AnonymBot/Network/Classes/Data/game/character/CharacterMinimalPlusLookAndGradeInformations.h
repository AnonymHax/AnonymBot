#ifndef CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H
#define CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class CharacterMinimalPlusLookAndGradeInformations : public CharacterMinimalPlusLookInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterMinimalPlusLookAndGradeInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterMinimalPlusLookAndGradeInformations(Reader *param1);
  CharacterMinimalPlusLookAndGradeInformations();
  bool operator==(const CharacterMinimalPlusLookAndGradeInformations &compared);

  uint grade;
};

#endif // CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H