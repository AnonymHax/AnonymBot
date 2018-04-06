#ifndef ACHIEVEMENTREWARDERRORMESSAGE_H
#define ACHIEVEMENTREWARDERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AchievementRewardErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementRewardErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementRewardErrorMessage(Reader *param1);
  AchievementRewardErrorMessage();

  int achievementId;
};

#endif // ACHIEVEMENTREWARDERRORMESSAGE_H