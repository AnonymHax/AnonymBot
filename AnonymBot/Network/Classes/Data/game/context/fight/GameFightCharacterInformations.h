#ifndef GAMEFIGHTCHARACTERINFORMATIONS_H
#define GAMEFIGHTCHARACTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterNamedInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterNamedInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"

class GameFightCharacterInformations : public GameFightFighterNamedInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightCharacterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightCharacterInformations(Reader *param1);
  GameFightCharacterInformations();
  bool operator==(const GameFightCharacterInformations &compared);

  uint level;
  ActorAlignmentInformations alignmentInfos;
  int breed;
  bool sex;
};

#endif // GAMEFIGHTCHARACTERINFORMATIONS_H