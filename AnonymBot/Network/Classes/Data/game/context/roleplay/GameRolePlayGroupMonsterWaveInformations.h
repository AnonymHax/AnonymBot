#ifndef GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayGroupMonsterWaveInformations : public GameRolePlayGroupMonsterInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayGroupMonsterWaveInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayGroupMonsterWaveInformations(Reader *param1);
  GameRolePlayGroupMonsterWaveInformations();
  bool operator==(const GameRolePlayGroupMonsterWaveInformations &compared);

  uint nbWaves;
  QList<QSharedPointer<GroupMonsterStaticInformations>> alternatives;
};

#endif // GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H