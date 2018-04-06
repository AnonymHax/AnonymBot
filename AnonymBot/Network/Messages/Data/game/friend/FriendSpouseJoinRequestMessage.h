#ifndef FRIENDSPOUSEJOINREQUESTMESSAGE_H
#define FRIENDSPOUSEJOINREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendSpouseJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendSpouseJoinRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendSpouseJoinRequestMessage(Reader *param1);
  FriendSpouseJoinRequestMessage();
};

#endif // FRIENDSPOUSEJOINREQUESTMESSAGE_H