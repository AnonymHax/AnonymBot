#ifndef FRIENDDELETEREQUESTMESSAGE_H
#define FRIENDDELETEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendDeleteRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendDeleteRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendDeleteRequestMessage(Reader *param1);
  FriendDeleteRequestMessage();

  uint accountId;
};

#endif // FRIENDDELETEREQUESTMESSAGE_H