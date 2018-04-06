#ifndef ACHIEVEMENTDETAILEDLISTMESSAGE_H
#define ACHIEVEMENTDETAILEDLISTMESSAGE_H

#include "Network/Classes/Data/game/achievement/Achievement.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/achievement/Achievement.h"

class AchievementDetailedListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementDetailedListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementDetailedListMessage(Reader *param1);
  AchievementDetailedListMessage();

  QList<Achievement> startedAchievements;
  QList<Achievement> finishedAchievements;
};

#endif // ACHIEVEMENTDETAILEDLISTMESSAGE_H