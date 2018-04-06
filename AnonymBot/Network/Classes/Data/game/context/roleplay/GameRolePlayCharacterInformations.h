#ifndef GAMEROLEPLAYCHARACTERINFORMATIONS_H
#define GAMEROLEPLAYCHARACTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayCharacterInformations : public GameRolePlayHumanoidInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayCharacterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayCharacterInformations(Reader *param1);
  GameRolePlayCharacterInformations();
  bool operator==(const GameRolePlayCharacterInformations &compared);

  ActorAlignmentInformations alignmentInfos;
};

#endif // GAMEROLEPLAYCHARACTERINFORMATIONS_H