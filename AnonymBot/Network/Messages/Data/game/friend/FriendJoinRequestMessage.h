#ifndef FRIENDJOINREQUESTMESSAGE_H
#define FRIENDJOINREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendJoinRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendJoinRequestMessage(Reader *param1);
  FriendJoinRequestMessage();

  QString name;
};

#endif // FRIENDJOINREQUESTMESSAGE_H