#ifndef GAMEFIGHTCOMPANIONINFORMATIONS_H
#define GAMEFIGHTCOMPANIONINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameFightCompanionInformations : public GameFightFighterInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightCompanionInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightCompanionInformations(Reader *param1);
  GameFightCompanionInformations();
  bool operator==(const GameFightCompanionInformations &compared);

  uint companionGenericId;
  uint level;
  double masterId;
};

#endif // GAMEFIGHTCOMPANIONINFORMATIONS_H