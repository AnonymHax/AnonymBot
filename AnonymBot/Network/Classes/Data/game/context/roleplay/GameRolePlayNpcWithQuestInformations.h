#ifndef GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H
#define GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayNpcWithQuestInformations : public GameRolePlayNpcInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayNpcWithQuestInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayNpcWithQuestInformations(Reader *param1);
  GameRolePlayNpcWithQuestInformations();
  bool operator==(const GameRolePlayNpcWithQuestInformations &compared);

  GameRolePlayNpcQuestFlag questFlag;
};

#endif // GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H