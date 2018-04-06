#ifndef FRIENDSPOUSEONLINEINFORMATIONS_H
#define FRIENDSPOUSEONLINEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/friend/FriendSpouseInformations.h"
#include "Network/Classes/Data/game/friend/FriendSpouseInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class FriendSpouseOnlineInformations : public FriendSpouseInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendSpouseOnlineInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendSpouseOnlineInformations(Reader *param1);
  FriendSpouseOnlineInformations();
  bool operator==(const FriendSpouseOnlineInformations &compared);

  uint mapId;
  uint subAreaId;
  bool inFight;
  bool followSpouse;
};

#endif // FRIENDSPOUSEONLINEINFORMATIONS_H