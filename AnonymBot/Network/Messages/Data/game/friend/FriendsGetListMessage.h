#ifndef FRIENDSGETLISTMESSAGE_H
#define FRIENDSGETLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendsGetListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendsGetListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendsGetListMessage(Reader *param1);
  FriendsGetListMessage();
};

#endif // FRIENDSGETLISTMESSAGE_H