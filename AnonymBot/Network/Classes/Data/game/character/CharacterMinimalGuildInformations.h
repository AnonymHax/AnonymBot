#ifndef CHARACTERMINIMALGUILDINFORMATIONS_H
#define CHARACTERMINIMALGUILDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class CharacterMinimalGuildInformations : public CharacterMinimalPlusLookInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterMinimalGuildInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterMinimalGuildInformations(Reader *param1);
  CharacterMinimalGuildInformations();
  bool operator==(const CharacterMinimalGuildInformations &compared);

  QSharedPointer<BasicGuildInformations> guild;
};

#endif // CHARACTERMINIMALGUILDINFORMATIONS_H