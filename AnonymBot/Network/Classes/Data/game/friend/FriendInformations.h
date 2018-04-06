#ifndef FRIENDINFORMATIONS_H
#define FRIENDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/friend/AbstractContactInformations.h"
#include "Network/Classes/Data/game/friend/AbstractContactInformations.h"

class FriendInformations : public AbstractContactInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendInformations(Reader *param1);
  FriendInformations();
  bool operator==(const FriendInformations &compared);

  uint playerState;
  uint lastConnection;
  int achievementPoints;
};

#endif // FRIENDINFORMATIONS_H