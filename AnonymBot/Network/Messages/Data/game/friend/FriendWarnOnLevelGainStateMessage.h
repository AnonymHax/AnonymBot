#ifndef FRIENDWARNONLEVELGAINSTATEMESSAGE_H
#define FRIENDWARNONLEVELGAINSTATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendWarnOnLevelGainStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendWarnOnLevelGainStateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendWarnOnLevelGainStateMessage(Reader *param1);
  FriendWarnOnLevelGainStateMessage();

  bool enable;
};

#endif // FRIENDWARNONLEVELGAINSTATEMESSAGE_H