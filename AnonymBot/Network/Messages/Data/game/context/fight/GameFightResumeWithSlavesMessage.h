#ifndef GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H
#define GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightResumeSlaveInfo.h"
#include "Network/Classes/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Classes/Data/game/context/fight/GameFightSpellCooldown.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/fight/GameFightResumeMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightResumeSlaveInfo.h"
#include "Network/Classes/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Classes/Data/game/context/fight/GameFightSpellCooldown.h"

class GameFightResumeWithSlavesMessage : public GameFightResumeMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightResumeWithSlavesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightResumeWithSlavesMessage(Reader *param1);
  GameFightResumeWithSlavesMessage();

  QList<GameFightResumeSlaveInfo> slavesInfo;
};

#endif // GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H