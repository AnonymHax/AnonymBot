#ifndef CHARACTERREMODELINGINFORMATION_H
#define CHARACTERREMODELINGINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/AbstractCharacterInformation.h"
#include "Network/Classes/Data/game/character/AbstractCharacterInformation.h"

class CharacterRemodelingInformation : public AbstractCharacterInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterRemodelingInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterRemodelingInformation(Reader *param1);
  CharacterRemodelingInformation();
  bool operator==(const CharacterRemodelingInformation &compared);

  QString name;
  int breed;
  bool sex;
  uint cosmeticId;
  QList<int> colors;
};

#endif // CHARACTERREMODELINGINFORMATION_H