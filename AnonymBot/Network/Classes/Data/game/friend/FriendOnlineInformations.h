#ifndef FRIENDONLINEINFORMATIONS_H
#define FRIENDONLINEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Enum/Data/PlayableBreedEnum.h"
#include "Network/Classes/ClassManager.h"

class FriendOnlineInformations : public FriendInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendOnlineInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendOnlineInformations(Reader *param1);
  FriendOnlineInformations();
  bool operator==(const FriendOnlineInformations &compared);

  double playerId;
  QString playerName;
  uint level;
  int alignmentSide;
  int breed;
  bool sex;
  QSharedPointer<GuildInformations> guildInfo;
  uint moodSmileyId;
  QSharedPointer<PlayerStatus> status;
};

#endif // FRIENDONLINEINFORMATIONS_H