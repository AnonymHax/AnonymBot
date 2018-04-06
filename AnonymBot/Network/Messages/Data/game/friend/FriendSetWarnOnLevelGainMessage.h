#ifndef FRIENDSETWARNONLEVELGAINMESSAGE_H
#define FRIENDSETWARNONLEVELGAINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendSetWarnOnLevelGainMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendSetWarnOnLevelGainMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendSetWarnOnLevelGainMessage(Reader *param1);
  FriendSetWarnOnLevelGainMessage();

  bool enable;
};

#endif // FRIENDSETWARNONLEVELGAINMESSAGE_H