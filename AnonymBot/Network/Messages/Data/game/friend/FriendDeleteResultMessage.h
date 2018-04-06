#ifndef FRIENDDELETERESULTMESSAGE_H
#define FRIENDDELETERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendDeleteResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendDeleteResultMessage(Reader *param1);
  FriendDeleteResultMessage();

  bool success;
  QString name;
};

#endif // FRIENDDELETERESULTMESSAGE_H