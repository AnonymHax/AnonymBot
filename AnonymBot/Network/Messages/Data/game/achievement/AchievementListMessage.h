#ifndef ACHIEVEMENTLISTMESSAGE_H
#define ACHIEVEMENTLISTMESSAGE_H

#include "Network/Classes/Data/game/achievement/AchievementRewardable.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/achievement/AchievementRewardable.h"

class AchievementListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementListMessage(Reader *param1);
  AchievementListMessage();

  QList<uint> finishedAchievementsIds;
  QList<AchievementRewardable> rewardableAchievements;
};

#endif // ACHIEVEMENTLISTMESSAGE_H