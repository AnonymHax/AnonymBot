#ifndef FRIENDWARNONCONNECTIONSTATEMESSAGE_H
#define FRIENDWARNONCONNECTIONSTATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendWarnOnConnectionStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendWarnOnConnectionStateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendWarnOnConnectionStateMessage(Reader *param1);
  FriendWarnOnConnectionStateMessage();

  bool enable;
};

#endif // FRIENDWARNONCONNECTIONSTATEMESSAGE_H