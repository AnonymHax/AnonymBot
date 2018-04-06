#ifndef GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H
#define GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameFightFighterNamedInformations : public GameFightFighterInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterNamedInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterNamedInformations(Reader *param1);
  GameFightFighterNamedInformations();
  bool operator==(const GameFightFighterNamedInformations &compared);

  QString name;
  QSharedPointer<PlayerStatus> status;
};

#endif // GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H