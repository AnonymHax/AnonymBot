#ifndef GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayGroupMonsterInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayGroupMonsterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayGroupMonsterInformations(Reader *param1);
  GameRolePlayGroupMonsterInformations();
  bool operator==(const GameRolePlayGroupMonsterInformations &compared);

  QSharedPointer<GroupMonsterStaticInformations> staticInfos;
  double creationTime;
  uint ageBonusRate;
  int lootShare;
  int alignmentSide;
  bool keyRingBonus;
  bool hasHardcoreDrop;
  bool hasAVARewardToken;
};

#endif // GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H