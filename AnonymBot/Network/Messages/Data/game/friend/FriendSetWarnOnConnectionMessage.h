#ifndef FRIENDSETWARNONCONNECTIONMESSAGE_H
#define FRIENDSETWARNONCONNECTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendSetWarnOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendSetWarnOnConnectionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendSetWarnOnConnectionMessage(Reader *param1);
  FriendSetWarnOnConnectionMessage();

  bool enable;
};

#endif // FRIENDSETWARNONCONNECTIONMESSAGE_H