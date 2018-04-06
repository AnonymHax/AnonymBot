#ifndef GAMEFIGHTENDMESSAGE_H
#define GAMEFIGHTENDMESSAGE_H

#include "Network/Classes/Data/game/context/fight/FightResultListEntry.h"
#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeamWithOutcome.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/FightResultListEntry.h"
#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeamWithOutcome.h"
#include "Network/Classes/ClassManager.h"

class GameFightEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightEndMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightEndMessage(Reader *param1);
  GameFightEndMessage();

  uint duration;
  int ageBonus;
  int lootShareLimitMalus;
  QList<QSharedPointer<FightResultListEntry>> results;
  QList<NamedPartyTeamWithOutcome> namedPartyTeamsOutcomes;
};

#endif // GAMEFIGHTENDMESSAGE_H