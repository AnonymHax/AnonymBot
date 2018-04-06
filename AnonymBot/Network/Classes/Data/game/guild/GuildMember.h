#ifndef GUILDMEMBER_H
#define GUILDMEMBER_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/ClassManager.h"

class GuildMember : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMember(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMember(Reader *param1);
  GuildMember();
  bool operator==(const GuildMember &compared);

  int breed;
  bool sex;
  uint rank;
  double givenExperience;
  uint experienceGivenPercent;
  uint rights;
  uint connected;
  int alignmentSide;
  uint hoursSinceLastConnection;
  uint moodSmileyId;
  uint accountId;
  int achievementPoints;
  QSharedPointer<PlayerStatus> status;
};

#endif // GUILDMEMBER_H