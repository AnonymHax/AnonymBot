#ifndef GAMEFIGHTMONSTERINFORMATIONS_H
#define GAMEFIGHTMONSTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightAIInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightAIInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameFightMonsterInformations : public GameFightAIInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightMonsterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightMonsterInformations(Reader *param1);
  GameFightMonsterInformations();
  bool operator==(const GameFightMonsterInformations &compared);

  uint creatureGenericId;
  uint creatureGrade;
};

#endif // GAMEFIGHTMONSTERINFORMATIONS_H