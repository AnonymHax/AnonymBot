#ifndef GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"

class GameFightFighterNamedLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterNamedLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterNamedLightInformations(Reader *param1);
  GameFightFighterNamedLightInformations();
  bool operator==(const GameFightFighterNamedLightInformations &compared);

  QString name;
};

#endif // GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H