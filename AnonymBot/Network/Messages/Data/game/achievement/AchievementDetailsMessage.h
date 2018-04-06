#ifndef ACHIEVEMENTDETAILSMESSAGE_H
#define ACHIEVEMENTDETAILSMESSAGE_H

#include "Network/Classes/Data/game/achievement/Achievement.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/achievement/Achievement.h"

class AchievementDetailsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementDetailsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementDetailsMessage(Reader *param1);
  AchievementDetailsMessage();

  Achievement achievement;
};

#endif // ACHIEVEMENTDETAILSMESSAGE_H