#ifndef FRIENDADDEDMESSAGE_H
#define FRIENDADDEDMESSAGE_H

#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/ClassManager.h"

class FriendAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendAddedMessage(Reader *param1);
  FriendAddedMessage();

  QSharedPointer<FriendInformations> friendAdded;
};

#endif // FRIENDADDEDMESSAGE_H