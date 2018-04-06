#ifndef NAMEDPARTYTEAMWITHOUTCOME_H
#define NAMEDPARTYTEAMWITHOUTCOME_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeam.h"

class NamedPartyTeamWithOutcome : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NamedPartyTeamWithOutcome(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NamedPartyTeamWithOutcome(Reader *param1);
  NamedPartyTeamWithOutcome();
  bool operator==(const NamedPartyTeamWithOutcome &compared);

  NamedPartyTeam team;
  uint outcome;
};

#endif // NAMEDPARTYTEAMWITHOUTCOME_H