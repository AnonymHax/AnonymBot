#ifndef GAMEFIGHTTAXCOLLECTORINFORMATIONS_H
#define GAMEFIGHTTAXCOLLECTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightAIInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightAIInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameFightTaxCollectorInformations : public GameFightAIInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTaxCollectorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTaxCollectorInformations(Reader *param1);
  GameFightTaxCollectorInformations();
  bool operator==(const GameFightTaxCollectorInformations &compared);

  uint firstNameId;
  uint lastNameId;
  uint level;
};

#endif // GAMEFIGHTTAXCOLLECTORINFORMATIONS_H