#ifndef CHARACTERTORELOOKINFORMATION_H
#define CHARACTERTORELOOKINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/choice/AbstractCharacterToRefurbishInformation.h"

class CharacterToRelookInformation : public AbstractCharacterToRefurbishInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterToRelookInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterToRelookInformation(Reader *param1);
  CharacterToRelookInformation();
  bool operator==(const CharacterToRelookInformation &compared);
};

#endif // CHARACTERTORELOOKINFORMATION_H