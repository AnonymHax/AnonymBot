#ifndef FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H
#define FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendGuildWarnOnAchievementCompleteStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Reader *param1);
  FriendGuildWarnOnAchievementCompleteStateMessage();

  bool enable;
};

#endif // FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H