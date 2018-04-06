#ifndef ACHIEVEMENTREWARDSUCCESSMESSAGE_H
#define ACHIEVEMENTREWARDSUCCESSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AchievementRewardSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementRewardSuccessMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementRewardSuccessMessage(Reader *param1);
  AchievementRewardSuccessMessage();

  int achievementId;
};

#endif // ACHIEVEMENTREWARDSUCCESSMESSAGE_H