#ifndef GAMEFIGHTFIGHTERCOMPANIONLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERCOMPANIONLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"

class GameFightFighterCompanionLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterCompanionLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterCompanionLightInformations(Reader *param1);
  GameFightFighterCompanionLightInformations();
  bool operator==(const GameFightFighterCompanionLightInformations &compared);

  uint companionId;
  double masterId;
};

#endif // GAMEFIGHTFIGHTERCOMPANIONLIGHTINFORMATIONS_H