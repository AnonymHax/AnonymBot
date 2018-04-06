#ifndef GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H
#define GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMonsterInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMonsterInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameFightMonsterWithAlignmentInformations : public GameFightMonsterInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightMonsterWithAlignmentInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightMonsterWithAlignmentInformations(Reader *param1);
  GameFightMonsterWithAlignmentInformations();
  bool operator==(const GameFightMonsterWithAlignmentInformations &compared);

  ActorAlignmentInformations alignmentInfos;
};

#endif // GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H