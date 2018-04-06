#ifndef FRIENDADDFAILUREMESSAGE_H
#define FRIENDADDFAILUREMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendAddFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendAddFailureMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendAddFailureMessage(Reader *param1);
  FriendAddFailureMessage();

  uint reason;
};

#endif // FRIENDADDFAILUREMESSAGE_H