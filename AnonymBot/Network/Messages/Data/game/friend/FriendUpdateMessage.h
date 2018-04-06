#ifndef FRIENDUPDATEMESSAGE_H
#define FRIENDUPDATEMESSAGE_H

#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/ClassManager.h"

class FriendUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendUpdateMessage(Reader *param1);
  FriendUpdateMessage();

  QSharedPointer<FriendInformations> friendUpdated;
};

#endif // FRIENDUPDATEMESSAGE_H