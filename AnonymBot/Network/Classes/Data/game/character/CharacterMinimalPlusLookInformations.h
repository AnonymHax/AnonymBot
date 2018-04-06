#ifndef CHARACTERMINIMALPLUSLOOKINFORMATIONS_H
#define CHARACTERMINIMALPLUSLOOKINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class CharacterMinimalPlusLookInformations : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterMinimalPlusLookInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterMinimalPlusLookInformations(Reader *param1);
  CharacterMinimalPlusLookInformations();
  bool operator==(const CharacterMinimalPlusLookInformations &compared);

  QSharedPointer<EntityLook> entityLook;
};

#endif // CHARACTERMINIMALPLUSLOOKINFORMATIONS_H