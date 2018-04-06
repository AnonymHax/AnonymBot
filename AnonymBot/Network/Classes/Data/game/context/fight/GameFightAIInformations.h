#ifndef GAMEFIGHTAIINFORMATIONS_H
#define GAMEFIGHTAIINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameFightAIInformations : public GameFightFighterInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightAIInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightAIInformations(Reader *param1);
  GameFightAIInformations();
  bool operator==(const GameFightAIInformations &compared);
};

#endif // GAMEFIGHTAIINFORMATIONS_H