#ifndef GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"

class GameFightFighterTaxCollectorLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterTaxCollectorLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterTaxCollectorLightInformations(Reader *param1);
  GameFightFighterTaxCollectorLightInformations();
  bool operator==(const GameFightFighterTaxCollectorLightInformations &compared);

  uint firstNameId;
  uint lastNameId;
};

#endif // GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS_H