#ifndef GAMEFIGHTMINIMALSTATSPREPARATION_H
#define GAMEFIGHTMINIMALSTATSPREPARATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"

class GameFightMinimalStatsPreparation : public GameFightMinimalStats
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightMinimalStatsPreparation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightMinimalStatsPreparation(Reader *param1);
  GameFightMinimalStatsPreparation();
  bool operator==(const GameFightMinimalStatsPreparation &compared);

  uint initiative;
};

#endif // GAMEFIGHTMINIMALSTATSPREPARATION_H