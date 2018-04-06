#ifndef GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"

class GameFightFighterMonsterLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterMonsterLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterMonsterLightInformations(Reader *param1);
  GameFightFighterMonsterLightInformations();
  bool operator==(const GameFightFighterMonsterLightInformations &compared);

  uint creatureGenericId;
};

#endif // GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS_H