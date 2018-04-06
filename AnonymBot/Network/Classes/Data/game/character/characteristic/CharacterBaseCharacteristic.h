#ifndef CHARACTERBASECHARACTERISTIC_H
#define CHARACTERBASECHARACTERISTIC_H

#include "Network/Classes/AbstractClass.h"

class CharacterBaseCharacteristic : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterBaseCharacteristic(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterBaseCharacteristic(Reader *param1);
  CharacterBaseCharacteristic();
  bool operator==(const CharacterBaseCharacteristic &compared);

  int base;
  int additionnal;
  int objectsAndMountBonus;
  int alignGiftBonus;
  int contextModif;
};

#endif // CHARACTERBASECHARACTERISTIC_H