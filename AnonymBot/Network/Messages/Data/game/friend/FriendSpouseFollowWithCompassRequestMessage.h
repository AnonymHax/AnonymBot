#ifndef FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE_H
#define FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendSpouseFollowWithCompassRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendSpouseFollowWithCompassRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendSpouseFollowWithCompassRequestMessage(Reader *param1);
  FriendSpouseFollowWithCompassRequestMessage();

  bool enable;
};

#endif // FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE_H