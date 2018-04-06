#ifndef CHARACTERSPELLMODIFICATION_H
#define CHARACTERSPELLMODIFICATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterBaseCharacteristic.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterBaseCharacteristic.h"

class CharacterSpellModification : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSpellModification(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSpellModification(Reader *param1);
  CharacterSpellModification();
  bool operator==(const CharacterSpellModification &compared);

  uint modificationType;
  uint spellId;
  CharacterBaseCharacteristic value;
};

#endif // CHARACTERSPELLMODIFICATION_H