#ifndef FRIENDADDREQUESTMESSAGE_H
#define FRIENDADDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendAddRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendAddRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendAddRequestMessage(Reader *param1);
  FriendAddRequestMessage();

  QString name;
};

#endif // FRIENDADDREQUESTMESSAGE_H