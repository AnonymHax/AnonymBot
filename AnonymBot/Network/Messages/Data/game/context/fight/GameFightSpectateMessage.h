#ifndef GAMEFIGHTSPECTATEMESSAGE_H
#define GAMEFIGHTSPECTATEMESSAGE_H

#include "Network/Classes/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Classes/Data/game/idol/Idol.h"

class GameFightSpectateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightSpectateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightSpectateMessage(Reader *param1);
  GameFightSpectateMessage();

  QList<QSharedPointer<FightDispellableEffectExtendedInformations>> effects;
  QList<GameActionMark> marks;
  uint gameTurn;
  uint fightStart;
  QList<QSharedPointer<Idol>> idols;
};

#endif // GAMEFIGHTSPECTATEMESSAGE_H