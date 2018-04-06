#ifndef REFRESHCHARACTERSTATSMESSAGE_H
#define REFRESHCHARACTERSTATSMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"

class RefreshCharacterStatsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_RefreshCharacterStatsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_RefreshCharacterStatsMessage(Reader *param1);
  RefreshCharacterStatsMessage();

  double fighterId;
  QSharedPointer<GameFightMinimalStats> stats;
};

#endif // REFRESHCHARACTERSTATSMESSAGE_H