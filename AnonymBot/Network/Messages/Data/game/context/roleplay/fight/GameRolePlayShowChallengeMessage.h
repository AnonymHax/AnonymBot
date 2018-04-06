#ifndef GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H
#define GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H

#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"

class GameRolePlayShowChallengeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayShowChallengeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayShowChallengeMessage(Reader *param1);
  GameRolePlayShowChallengeMessage();

  QSharedPointer<FightCommonInformations> commonsInfos;
};

#endif // GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H