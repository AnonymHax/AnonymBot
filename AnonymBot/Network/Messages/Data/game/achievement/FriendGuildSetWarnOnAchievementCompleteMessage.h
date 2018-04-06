#ifndef FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H
#define FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FriendGuildSetWarnOnAchievementCompleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Reader *param1);
  FriendGuildSetWarnOnAchievementCompleteMessage();

  bool enable;
};

#endif // FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H