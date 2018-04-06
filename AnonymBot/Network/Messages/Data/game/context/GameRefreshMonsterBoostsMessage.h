#ifndef GAMEREFRESHMONSTERBOOSTSMESSAGE_H
#define GAMEREFRESHMONSTERBOOSTSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/MonsterBoosts.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/MonsterBoosts.h"

class GameRefreshMonsterBoostsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRefreshMonsterBoostsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRefreshMonsterBoostsMessage(Reader *param1);
  GameRefreshMonsterBoostsMessage();

  QList<MonsterBoosts> monsterBoosts;
  QList<MonsterBoosts> familyBoosts;
};

#endif // GAMEREFRESHMONSTERBOOSTSMESSAGE_H