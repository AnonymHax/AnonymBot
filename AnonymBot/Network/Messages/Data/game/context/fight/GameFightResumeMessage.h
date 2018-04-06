#ifndef GAMEFIGHTRESUMEMESSAGE_H
#define GAMEFIGHTRESUMEMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightSpellCooldown.h"
#include "Network/Classes/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/fight/GameFightSpectateMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightSpellCooldown.h"
#include "Network/Classes/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Classes/Data/game/idol/Idol.h"

class GameFightResumeMessage : public GameFightSpectateMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightResumeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightResumeMessage(Reader *param1);
  GameFightResumeMessage();

  QList<GameFightSpellCooldown> spellCooldowns;
  uint summonCount;
  uint bombCount;
};

#endif // GAMEFIGHTRESUMEMESSAGE_H