#ifndef GAMEFIGHTMUTANTINFORMATIONS_H
#define GAMEFIGHTMUTANTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterNamedInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterNamedInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"

class GameFightMutantInformations : public GameFightFighterNamedInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightMutantInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightMutantInformations(Reader *param1);
  GameFightMutantInformations();
  bool operator==(const GameFightMutantInformations &compared);

  uint powerLevel;
};

#endif // GAMEFIGHTMUTANTINFORMATIONS_H