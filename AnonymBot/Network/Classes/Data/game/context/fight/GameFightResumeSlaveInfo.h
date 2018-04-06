#ifndef GAMEFIGHTRESUMESLAVEINFO_H
#define GAMEFIGHTRESUMESLAVEINFO_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/GameFightSpellCooldown.h"

class GameFightResumeSlaveInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightResumeSlaveInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightResumeSlaveInfo(Reader *param1);
  GameFightResumeSlaveInfo();
  bool operator==(const GameFightResumeSlaveInfo &compared);

  double slaveId;
  QList<GameFightSpellCooldown> spellCooldowns;
  uint summonCount;
  uint bombCount;
};

#endif // GAMEFIGHTRESUMESLAVEINFO_H