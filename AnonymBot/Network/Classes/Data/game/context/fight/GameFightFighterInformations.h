#ifndef GAMEFIGHTFIGHTERINFORMATIONS_H
#define GAMEFIGHTFIGHTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/ClassManager.h"

class GameFightFighterInformations : public GameContextActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterInformations(Reader *param1);
  GameFightFighterInformations();
  bool operator==(const GameFightFighterInformations &compared);

  uint teamId;
  uint wave;
  bool alive;
  QSharedPointer<GameFightMinimalStats> stats;
  QList<uint> previousPositions;
};

#endif // GAMEFIGHTFIGHTERINFORMATIONS_H