#ifndef FRIENDSLISTMESSAGE_H
#define FRIENDSLISTMESSAGE_H

#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/ClassManager.h"

class FriendsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendsListMessage(Reader *param1);
  FriendsListMessage();

  QList<QSharedPointer<FriendInformations>> friendsList;
};

#endif // FRIENDSLISTMESSAGE_H